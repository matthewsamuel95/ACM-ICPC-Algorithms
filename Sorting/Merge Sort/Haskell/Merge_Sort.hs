mergesort :: (Ord a) => [a] -> [a]
mergesort []  = []
mergesort [x] = [x]
mergesort xs  = let (a,b) = splitAt (div (length xs) 2) xs
                in merge (mergesort a) (mergesort b)

merge :: (Ord a) => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys)
    | (x <= y) = x:(merge xs (y:ys))
    |otherwise = y:(merge (x:xs) ys)

main = do
    let result = mergesort [5, 0, -3, 4, 1, 3, 1, -5, 0, 9, 1]
    print result
