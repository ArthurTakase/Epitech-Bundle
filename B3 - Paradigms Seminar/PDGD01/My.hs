mySucc :: Int -> Int
mySucc n = n + 1

myIsNeg :: Int -> Bool
myIsNeg n = n < 0

myAbs :: Int -> Int
myAbs n | myIsNeg n = n * (-1)
        | otherwise = n

myMin :: Int -> Int -> Int
myMin a b | a < b = a
          | otherwise = b

myMax :: Int -> Int -> Int
myMax a b | a < b = b
          | otherwise = a

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b , a)

myHead :: [a] -> a
myHead [] = error "Empty List"
myHead (x:xs) = x

myTail :: [a] -> [a]
myTail [] = error "Empty List"
myTail (x:xs) = xs

myLength  :: [a] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs

myNth :: [a] -> Int -> a
myNth l 0 = myHead l
myNth l n | n < 0 = error "Negative Index"
          | myLength l <= n = error "Too Large"
          | otherwise = myNth (myTail l) (n - 1)

myTake :: Int -> [a] -> [a]
myTake 0 _ = []
myTake n l | myLength l < n = l
           | myIsNeg n = error "Negative Index"
           | otherwise = myHead l : myTake (n - 1) (myTail l)

myDrop :: Int -> [a] -> [a]
myDrop 0 l = l
myDrop n l | myLength l < n = l
           | myIsNeg n = error "Negative Index"
           | otherwise = myDrop (n - 1) (myTail l)

myAppend :: [a] -> [a] -> [a]
myAppend [] m = m
myAppend (x:xs) m = x : myAppend xs m

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]

myInit :: [a] -> [a]
myInit [] = error "Empty List"
myInit l = myReverse (myTail (myReverse l))

myLast :: [a] -> a
myLast [] = error "Empty List"
myLast l = myHead (myReverse l)

myZip :: [a] -> [b] -> [(a, b)]
myZip _ [] = []
myZip [] _ = []
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((a, b) : xs) = (a : x1, b : x2)
    where (x1, x2) = myUnzip xs

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap function (x:xs) = function x : myMap function xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter function (x:xs) | function x = x : myFilter function xs
                         | otherwise = myFilter function xs

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl _ b [] = b
myFoldl function b (x:xs) = myFoldl function (function b x) xs

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr _ b [] = b
myFoldr function b (x:xs) = function x (myFoldr function b xs)

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])
myPartition f (x : xs) | f x = (x : x1, x2)
                       | otherwise = (x1, x : x2)
    where (x1, x2) = myPartition f xs

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort _ [] = []
myQuickSort function (x : xs) = myAppend (myQuickSort function part1) (x : myQuickSort function part2)
    where (part2, part1) = myPartition (function x) xs