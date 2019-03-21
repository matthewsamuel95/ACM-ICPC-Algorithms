def gcd(a,b):
  if a==0:
    return b
  else:
    return gcd(b%a,a)

c = gcd(100,35) # c = 5
print(c)   
