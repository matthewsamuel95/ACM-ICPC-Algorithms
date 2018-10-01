def power(a, b):
	if (b == 0): return 1
	elif (int(b % 2) == 0):
		return (power(a, int(b / 2)) *
			power(a, int(b / 2)))
	else:
		return (a * power(a, int(b / 2)) *
				power(a, int(b / 2)))


a = 2; b = 3
print(power(a, b))
