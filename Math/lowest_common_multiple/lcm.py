def lcm(num1, num2):
    """Returns the lowest common multiple of two given integers."""
    temp_num = num1
    while (temp_num % num2) != 0:
        temp_num += num1
    return temp_num
	
if __name__ == "__main__":
    print lcm(3, 9) # output is 9
    print lcm(24, 36) # output is 72
    print lcm(12, 80) # output is 240
