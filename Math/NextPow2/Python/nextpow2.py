"""
         Print next power of 2 for a given number

"""
#import the math library
import math
#function which calculates the nextpow of 2
def nextpow(x):
    #this would give us the power P , such that 2 ^ P = X.
    #ceil function to get the next number
    nextnum = float(math.ceil(math.log(x,2)))
    #2 ^ next number will be the required result.
    result = float(pow(2.0,nextnum))
    return  int(result)

#Enter your number
num = int(input("Enter a number: "))
#call a function
ans = nextpow(num)
#print answer
print(ans)
