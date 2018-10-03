module QueueStack 
    ( Stack (..)
    , Queue (..)
    , Pair (..)
    , CStack
    , CQueue
    ) where

import Data.Foldable (foldl', toList)

class Foldable s => Stack s where
    push :: a -> s a -> s a
    pop :: s a -> (Maybe a, s a)
    emptyStack :: s a

class Foldable q => Queue q where
    enqueue :: a -> q a -> q a
    dequeue :: q a -> (Maybe a, q a)
    emptyQueue :: q a

-- A Pair consists of two of the same data structure, where the second is
-- reversed. The pair represents the first structure prepended to the reverse
-- of the second structure.
newtype Pair f a = Pair (f a, f a)
instance (Foldable s, Show a) => Show (Pair s a) where
    show = show . toList

instance Foldable s => Foldable (Pair s) where
    foldr f acc (Pair (sin, sout)) = let
        acc' = foldl (flip f) acc sout
        in foldr f acc' sin

sReverse :: Stack s => s a -> s a
sReverse = foldl' (flip push) emptyStack

qReverse :: Queue q => q a -> q a
qReverse = foldl' (flip enqueue) emptyQueue

qAppend :: Queue q => q a -> q a -> q a
qAppend q1 q2 = foldr enqueue q2 q1

-- A pair of stacks behaves like a queue
instance Stack s => Queue (Pair s) where
    enqueue elem (Pair (sin, sout)) = Pair (push elem sin, sout)
    dequeue (Pair (sin, sout)) = case pop sout of
        (Just x, sout') -> (Just x, Pair (sin, sout'))
        (Nothing, _) -> let
            (elem, sout') = pop . sReverse $ sin 
            in (elem, Pair (emptyStack, sout'))
    emptyQueue = Pair (emptyStack, emptyStack)

-- A pair of Queues can behave like a stack
instance Queue q => Stack (Pair q) where
    push elem (Pair (qin, qout)) = Pair (enqueue elem qin, qout)
    pop (Pair (qin, qout)) = case dequeue qin of
        (Nothing, _) -> let
            (elem, qout') = dequeue qout
            in (elem, Pair (emptyQueue, qout'))
        (Just _, _) -> pop . Pair $ (emptyQueue, qout `qAppend` qReverse qin)
    emptyStack = Pair (emptyQueue, emptyQueue)

-- The canonical stack type is a list
type CStack = []
-- The canonical queue type is a pair of lists
type CQueue = Pair []

instance Stack [] where
    push = (:)
    pop [] = (Nothing, [])
    pop xs = (Just $ head xs, tail xs)
    emptyStack = []
