-- module PushSwap where
import System.Environment
import System.Exit

-- ###### GESTION D'ERREURS ######

-- Vérification de la viabilité des arguments
checkArgs :: [String] -> String -> IO()
checkArgs (x:xs) "move" | x `elem` ["sa", "sb", "sc", "pa", "pb", "ra",
                "rb", "rr", "rra", "rrb", "rrr"] = checkArgs xs "move"
                        | otherwise = exitWith (ExitFailure 84)
checkArgs (x:xs) "int"  | readInt x == Nothing = exitWith (ExitFailure 84)
                        | otherwise = checkArgs xs "int"
checkArgs _ _ = putStr ""

-- Conversion String vers Int (gestion d'erreur en cas de valeur non Int)
readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt l   | length l == result = Just (read l :: Int)
            | length l == result + 1 && head l == '-' &&
              length l /= 1 = Just (read l :: Int)
            | otherwise = Nothing
    where result = nbDigit l

-- Compte le nombre de chiffre dans le parametre
nbDigit :: [Char] -> Int
nbDigit [] = 0
nbDigit (x:xs)  | x `elem` "0123456789" = 1 + nbDigit xs
                | otherwise = nbDigit xs

-- ###### PUSHSWAP_CHECKER ######

-- Définition des différents mouvements
setMove :: ([Int], [Int]) -> String -> ([Int], [Int])
setMove (l_a, l_b) "sa" | length l_a <= 1 = (l_a, l_b)
                        | otherwise = (l_a !! 1 : head l_a : drop 2 l_a , l_b)
setMove (l_a, l_b) "sb" | length l_b <= 1 = (l_a, l_b)
                        | otherwise = (l_a, l_b !! 1 : head l_b : drop 2 l_b)
setMove (l_a, l_b) "sc" = setMove (setMove (l_a, l_b) "sa") "sb"
setMove (l_a, []) "pa" = (l_a, [])
setMove (l_a, l_b) "pa" = (head l_b : l_a, tail l_b)
setMove ([], l_b) "pb" = ([], l_b)
setMove (l_a, l_b) "pb" = (tail l_a, head l_a : l_b)
setMove (l_a, l_b) "rra" = (last l_a : init l_a, l_b)
setMove (l_a, l_b) "rrb" = (l_a, last l_b : init l_b)
setMove (l_a, l_b) "rrr" = setMove (setMove (l_a, l_b) "rra") "rrb"
setMove (l_a, l_b) "ra" = (tail l_a ++ [head l_a], l_b)
setMove (l_a, l_b) "rb" = (l_a, tail l_b ++ [head l_b])
setMove (l_a, l_b) "rr" = setMove (setMove (l_a, l_b) "ra") "rb"
setMove l _ = l

-- Vérification des listes après traitement
isOk :: ([Int], [Int]) -> Bool
isOk ([], []) = True
isOk ([x], []) = True
isOk (x:xs, []) = x <= head xs && isOk(xs, [])
isOk (_, _) = False

-- Algo principal
main :: IO ()
main = do
    args <- getArgs
    instructions <- fmap words getLine
    checkArgs args "int"
    checkArgs instructions "move"
    let (l_a, l_b) = foldl setMove (map read args, []) instructions
    if isOk (l_a, l_b) then putStrLn "OK"
    else putStr "KO: " >> print (l_a, l_b) >> exitWith (ExitFailure 84)