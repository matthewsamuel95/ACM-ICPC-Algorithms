# There's a staircase with N steps, and you can climb 1 or 2 steps at a time. Given N, write a function that returns the number of unique
# ways you can climb the staircase. The order of the steps matters.

# For example, if N is 4, then there are 5 unique ways:

# 1, 1, 1, 1
# 2, 1, 1
# 1, 2, 1
# 1, 1, 2
# 2, 2

# What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? 
# For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time. Generalize your function to take in X.

# Solution using Dynamic Programming

# TC : O(N*|x|)
# SC : O(N)

def num_ways_X(n):
    if n==0:
        return 1
    total = 0
    for i in x:
        if n-i>=0:
            total+=num_ways_X(n-i)
    
    return total

def num_ways_dp(n):
    if n==0:
        return 1
    temp = [0]*(n+1)
    temp[0] = 1
    i = 1
    while i<n+1:
        total=0
        for j in x:
            if i-j>=0:
                total+=temp[i-j]
        temp[i]=total        
        i+=1        
    return temp[n]

x = [1,3,5]
for i in range(1,40):
    print(num_ways_dp(i))
   
    