from eulers_totient import phi

if __name__ == "__main__":
	for i in range(1, 11):
		print ("phi({}) == {}".format(i, phi(i)))