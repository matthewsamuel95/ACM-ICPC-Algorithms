#Generate prime numbers using the sieve of Eratosthenes.

import math

#Create a list of all the primes up to limit
#e.g. primes(11) returns [2, 3, 5, 7]
def primes(limit):

    #First, create a list of all the numbers up to limit
    numbers = list(range(limit))

    #Eliminate 0 and 1
    numbers[0] = 0
    numbers[1] = 0



    #For each number still in the list, eliminate all its multiples
    #We only need to check up to the square root of the biggest number
    for i in range(2, int(math.sqrt(limit)) + 1):
        if numbers[i] == 0:
            continue
        for j in range(i, limit, i):
            #Skip the first iteration of the loop
            if j == i:
                continue
            numbers[j] = 0
    return list(filter(lambda x: x != 0, numbers))
        
