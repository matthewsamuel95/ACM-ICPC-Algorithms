"""
         Print all factors of a given number

"""

#Enter your number
num = input("Enter a number: ");
#initialize your count as 0
count = 0;
number = int(num);
#run a loop to find factors
#Check the factors (starting with 2, until the number is reached)
for i in range(2, number-1):
    #If the divided number has 0 as the division reminder, it'll be a factor
    if number%i == 0:
        #Print this number everytime
        print(i);
        i += 1;
        count += 1;
#If number is not divisible by any number other than 1 and number itself,then it is prime
if count==0:
    print(number,"is a prime number.");
