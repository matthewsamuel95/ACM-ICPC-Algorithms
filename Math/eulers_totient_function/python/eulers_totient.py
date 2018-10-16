def gcd(a, b):
	if a == 0:
		return b

	return gcd(b % a, a)

def phi(n):
	res = 1

	for i in range(2, n):
		if gcd(i, n) == 1:
			res += 1

	return res