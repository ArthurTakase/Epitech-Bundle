import System.Environment
import System.Exit

-- TASK 01
myElem :: Eq a => a -> [a] -> Bool
myElem search [] = False
myElem search (x:xs) | search == x = True
                     | otherwise = myElem search xs

-- TASK 02
safeDiv :: Int -> Int -> Maybe Int
safeDiv a 0 = Nothing
safeDiv a b = Just (a `div` b)

-- TASK 03
safeNth :: [a] -> Int -> Maybe a
safeNth (x:xs) 0 = Just x
safeNth [] _ = Nothing
safeNth (x:xs) n | n < 0 = Nothing
                 | otherwise = safeNth xs (n - 1)

-- TASK 04
safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc n = fmap succ n

-- TASK 05
myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup _ [] = Nothing
myLookup search (x:xs) | search == fst x = Just (snd x)
                       | otherwise = myLookup search xs

-- TASK 06
maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing _ = Nothing
maybeDo _ _ Nothing = Nothing
maybeDo f a b = Just f <*> a  <*> b

-- TASK 07
readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt l | length l == result = Just (read l :: Int)
          | length l == result + 1 &&
            head l == '-' &&
            length l /= 1 = Just (read l :: Int)
          | otherwise = Nothing
    where result = nbDigit l

nbDigit :: [Char] -> Int
nbDigit [] = 0
nbDigit (x:xs) | myElem x "0123456789" = 1 + nbDigit xs
               | otherwise = nbDigit xs

-- TASK 08
getLineLength :: IO Int
getLineLength = fmap length getLine

-- TASK 09
printAndGetLength :: String -> IO Int
printAndGetLength s = putStrLn s >> return (length s)

-- TASK 10
printBox :: Int -> IO ()
printBox 0 = return ()
printBox 1 = putStrLn "+"
printBox n | n < 0 = return ()
           | otherwise = printLine (n * 2 - 2) '-' "+" >>
             printBorder (n - 2) (n * 2 - 2) >>
             printLine (n * 2 - 2) '-' "+"

printLine :: Int -> Char -> String -> IO ()
printLine n c b = putStr b >> putStr (replicate n c) >> putStrLn b

printBorder :: Int -> Int -> IO ()
printBorder 0 _ = putStr ""
printBorder n len = printLine len ' ' "|" >> printBorder (n - 1) len

-- TASK 11
concatLines :: Int -> IO String
concatLines 0 = return ""
concatLines n | n < 0 = return ""
              | otherwise = concatLines n ""
    where concatLines :: Int -> String -> IO String
          concatLines 0 acc = return acc
          concatLines n acc = getLine >>= \x -> concatLines (n - 1) (acc ++ x)

-- TASK 12
getInt :: IO ( Maybe Int )
getInt = readInt <$> getLine

-- TASK 13
doOp :: String -> String -> String -> Maybe Int
doOp a s b | readInt a == Nothing = Nothing
           | readInt b == Nothing = Nothing
doOp a "+" b = Just (read a + read b)
doOp a "-" b = Just (read a - read b)
doOp a "*" b = Just (read a * read b)
doOp a "/" b = safeDiv (read a) (read b)
doOp a "%" b = safeMod (read a) (read b)
doOp _ s _ = Nothing

safeMod :: Int -> Int -> Maybe Int
safeMod a 0 = Nothing
safeMod a b = Just (a `mod` b)

printMaybe :: Show a => Maybe a -> IO ()
printMaybe (Just x) = print x
printMaybe n = print n

main :: IO()
main = do
    args <- getArgs
    if length args == 3 then case doOp (args !! 0) (args !! 1) (args !! 2) of
        Nothing -> exitWith (ExitFailure 84)
        _ -> printMaybe (doOp (args !! 0) (args !! 1) (args !! 2))
    else exitWith (ExitFailure 84)