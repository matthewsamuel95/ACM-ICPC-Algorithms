def sqroot(x):
	if x == 0:
		return 0
		
	counter = 1
	while pow(counter, 2) <= x:
		counter += 1
	counter -= 1
	
	return counter
	

num = int(raw_input())
sqrt_num = sqroot(num)

print "The square root of the number %d is %d" % (num, sqrt_num)
