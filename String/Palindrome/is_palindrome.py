import re

def is_palindrome(s):
    """Checks if a given string is a palindrome."""
    if any(x.isupper() for x in s):
        s = re.sub(r'[^\w]', '', s).lower()        
    if len(s) < 2:
        return True
    if s[0] != s[-1]:
        return False
    return is_palindrome(s[1:-1])

if __name__ == "__main__":
    print is_palindrome("redivider") # output is True
    print is_palindrome("123321") # output is True
    print is_palindrome("palindrome") # output is False    
    print is_palindrome("On a clover, if alive, erupts a vast pure evil; a fire volcano") # output is True
