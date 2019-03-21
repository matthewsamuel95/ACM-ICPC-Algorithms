# Returns floor of square root of x
def sqrt(num) :
    if num == 0 or num == 1:
        return num
    start = 1
    end = num
    while start < end:
        mid = (start + end) // 2
        if (mid*mid == num) :
            return mid
        # Since we need floor, we update
        # answer when mid*mid is smaller
        # than x, and move closer to sqrt(x)
        if mid * mid < num:
            start = mid + 1
            ans = mid
        else :
            # If mid*mid is greater than x
            end = mid
    return ans

if __name__ == "__main__":
    print(sqrt(11)) #output is 3
    print(sqrt(4))  #output is 2
