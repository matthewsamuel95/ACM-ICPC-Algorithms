"""
         Print all permutations of a given list

"""

#We can do it by built-in permutation function in itertools library
#import the itertools library
import itertools
#call the permutation function of itertools library and pass list numbers as a argument
#this will print the list of permutations
print(list(itertools.permutations([1, 2, 3])))
