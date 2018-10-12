#!/usr/bin/python
import sys
import math

def is_prime(number):
    if (number <= 1):
        return False
    for i in range(2, 1 + int(math.sqrt(number))):
        if (number % i) == 0:
            return False
    return True

number = input("Enter a number : ")

if is_prime(int(number)):
    print '{} is a prime number'.format(number)
else:
    print '{} is not a prime number'.format(number)
