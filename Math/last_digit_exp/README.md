# Find Last Digit Of a^b for Large Numbers

- You are given two integer numbers , the base a (number of digits d, such that 1 <= d <= 1000) and the index b (0 <= b <= 922*10^15). You have to find the last digit of a^b.

- Examples:

- Input  : 3 10
- Output : 9

- Input  : 6 2
- Output : 6

- Input  : 150 53
- Output : 0


![alt text](http://cdncontribute.geeksforgeeks.org/wp-content/uploads/table4.png "Title")

Algorithm :

- Since number are very large we store them as a string.
- Take last digit in base a.
- Now calculate b%4. Here b is very large so we follow this approach to calculate mod of large number.
- If b%4==0 that means b is completely divisible by 4, so our exponent now will be exp = 4 because by multiplying number 4 times, we get the last digit according to cycle table in above diagram.
- If b%4!=0 that means b is not completely divisible by 4, so our exponent now will be exp=b%4 because by multiplying number exponent times, we get the last digit according to cycle table in above diagram.
- Now calculate ldigit = pow( last_digit_in_base, exp ).
- Last digit of a^b will be ldigit%10.
