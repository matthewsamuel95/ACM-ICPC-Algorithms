#!/usr/bin/python
import sys
import math

def is_prime(number):
    if number <= 1:
        return False
    if number == 2:
        return True
    if number % 2 == 0:
        return False

    for i in range(3, 1 + int(math.sqrt(number)), 2):
        if (number % i) == 0:
            return False
    return True

number = input("Enter a number : ")

if is_prime(int(number)):
    print '{} is a prime number'.format(number)
else:
    print '{} is not a prime number'.format(number)
