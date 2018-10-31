# Algorithm to find the product of two numbers in logarithmic time
def multiply(a,b):
    if a > b:
        left = a
        right = b
    else:
        left = b
        right = a
    
    prod = 0
    
    while left > 0: # Loop till you reach 1
        if left%2 != 0:  # Add the value to product variable if the left column value is odd
            prod = prod + right
        
        left = left >> 1 # Right shift
        right = right << 1 # Left Shift

    return prod
    
print(multiply(127,68))
