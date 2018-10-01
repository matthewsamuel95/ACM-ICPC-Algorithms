def power(x,n):
  orig_n = None
  c = 1
  r = x
  if n == 0:
    return 1
  if n < 0:
    orig_n = n
    n = orig_n + (-orig_n) + (-orig_n)
  while c < n:
    r = r * x
    c += 1
  if orig_n is None:
    return r
  else:
    r1 = 1 / float(r)
    return r1

