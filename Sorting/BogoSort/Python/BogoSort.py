import random
import unittest

# returns the sorted version of the given array by 
# checking first if its sorted, and then if not
# randomly shuffles elements in the given array
# and recursivly calls itself with the newly
# shuffled array as an arguement.
def monkeySort(arr1):
    for i in range(1, len(arr1)):
        if arr1[i-1] > arr1[i]:
            random.shuffle(arr1)
            return monkeySort(arr1)
    return arr1

class testMonkeySort(unittest.TestCase):

    def test_regular_arr(self):
        arrPractice = [3, 4, 2, 1 ,5]
        self.assertEqual(monkeySort(arrPractice), [1, 2, 3, 4, 5])
    
    def test_same_arr(self):
        arrPractice = [1, 1, 1, 1, 1]
        self.assertEqual(monkeySort(arrPractice), arrPractice)   

    def test_empty_arr(self):
        arrPractice = []
        self.assertEqual(monkeySort(arrPractice), arrPractice)    

    def test_duplicate_arr(self):
        arrPractice = [4, 2, 2, 1, 1]
        arrSolution = [1, 1, 2, 2, 4]
        self.assertEqual(monkeySort(arrPractice), arrSolution)    
    
if __name__ == "__main__":
    unittest.main()
