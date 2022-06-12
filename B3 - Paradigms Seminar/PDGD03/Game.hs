import Data.Type.Bool (Not)
-- TASK 01
data Item = Sword | Bow | MagicWand

-- TASK 02
instance Eq Item where
    (==) Sword Sword = True
    (==) Bow Bow = True
    (==) MagicWand MagicWand = True
    (==) _ _ = False

-- TASK 03
instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

-- TASK 04
data Mob = Mummy | Skeleton Item | Witch (Maybe Item)

instance Eq Mob where
    (==) Mummy Mummy = True
    (==) (Skeleton a) (Skeleton b) = True
    (==) (Witch a) (Witch b) = True
    (==) _ _ = False

-- TASK 05
createMummy :: Mob
createMummy = Mummy 

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing 

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

-- TASK 06
create :: String -> Maybe Mob
create "mummy" = Just createMummy
create "doomed archer" = Just createArcher
create "dead knight" = Just createKnight
create "witch" = Just createWitch
create "sorceress" = Just createSorceress
create _ = Nothing

-- TASK 07
equip :: Item -> Mob -> Maybe Mob
equip _ Mummy = Nothing
equip item (Skeleton a) = Just (Skeleton item)
equip item (Witch a) = Just (Witch (Just item))

-- TASK 08
instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton a) = "skeleton holding a " ++ show a
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just a)) = "witch holding a " ++ show a

-- TASK 09
class HasItem a where
    getItem :: a -> Maybe Item
    hasItem :: a -> Bool

-- TASK 10
instance HasItem Mob where
    -- All HasItem
    hasItem Mummy = False
    hasItem (Skeleton a) = True 
    hasItem (Witch Nothing) = False
    hasItem _ = True 
    -- All GetItem
    getItem Mummy = Nothing
    getItem (Skeleton a) = Just a
    getItem (Witch Nothing) = Nothing
    getItem (Witch a) = a