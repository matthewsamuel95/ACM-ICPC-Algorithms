class InsertionSort:

	def __init__(self, lst):
		self.lst  = lst

	def sort(self):
		for i in range(1,len(self.lst)):
			key = self.lst[i]
			j = i - 1
			while j > -1 and self.lst[j] > key:
				self.lst[j+1] = self.lst[j]
				j = j - 1
			self.lst[j + 1] = key

	def show(self):
		return self.lst


if __name__ == "__main__":
	i = InsertionSort([5,4,3,2,1])
	i.sort();
	print i.show()
