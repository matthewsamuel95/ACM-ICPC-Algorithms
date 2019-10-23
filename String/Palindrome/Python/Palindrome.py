
def palindrome(s):
  if s == s[::-1]:
      return True
  else:
      return False
    
assert(palindrome('1234321')==True)
assert(palindrome('o')==True)
assert(palindrome('p250')==False)
assert(palindrome('palindrome')==False)
