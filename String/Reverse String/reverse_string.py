def reverse(string):
  s=""
  for i in range(0,len(string)):
    s+=string[len(string)-i-1]
    
 return s
  
if __name__ == '__main__':
  print(reverse("reverse")) # Output "esrever"
  print(reverse("Three can keep a secret, if two of them are dead")) # Output "daed era meht fo owt fi ,terces a peek nac eerhT"
  print(reverse("ACM-ICPC-Algorithms")) # Output "smhtiroglA-CPCI-MCA"
