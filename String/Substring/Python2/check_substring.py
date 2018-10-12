'''
This program takes in 2 strings as input, and checks if the second string is a 
sub string of the first string.
'''
def check_sub():
    print("This program checks if the second string you enter is a sub string\
            of the first string.")
    string1 = raw_input('Enter main string: ')
    string2 = raw_input('Enter second string: ')

    if string2 in string1:
        print("Second string is a sub-string of the first.")
    else:
       print("Secnd string is not a sub-string of the first.")

if __name__=='__main__':
    check_sub()
