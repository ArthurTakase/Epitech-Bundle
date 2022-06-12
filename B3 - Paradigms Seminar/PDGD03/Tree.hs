-- TASK 11
data Tree a = Empty | Node (Tree a) a (Tree a)
    deriving (Show)

-- TASK 12
-- addInTree :: Ord a = > a -> Tree a -> Tree a
-- addInTree

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree n Empty = Node Empty n Empty
addInTree n (Node left a right) | n < a = Node (addInTree n left) a right
                                | n > a = Node left a (addInTree n right)

-- TASK 13


-- TASK 14


-- TASK 15


-- TASK 16


-- TASK 17