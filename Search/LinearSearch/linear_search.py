"""
Created on Wed Oct 10 20:23:29 2018

@author: KARAN
"""

numbers = []
n = int(input("Enter the total number of elements :  "))
for i in range(n):
    numbers.append(int(input("Enter a number : ")))

key = int(input("Enter the number you wanna find in the list : "))
found = False
for i in range(n):
    if key == numbers[i]:
        print(key, " found at index ", i + 1, " ! :)")
        found = True
if not found:
    print(key, " not found in the list! :(")
