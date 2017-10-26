class MergeSort:

	def __init__(self, lst):
		self.lst = lst

	def mergeSort(self, a):
		midPoint = len(a)//2
		if a[len(a)-1] < a[0]:
			left = self.mergeSort(a[:midPoint])
			right = self.mergeSort(a[midPoint:])
			return self.merge(left, right)
		else:
			return a

	def merge(self, left, right):
		output = list()
		leftCount, rightCount = 0, 0
		while leftCount < len(left) or rightCount < len(right):
			if leftCount < len(left) and rightCount < len(right):
				if left[leftCount] < right[rightCount]:
					output.append(left[leftCount])
					leftCount += 1
				else:
					output.append(right[rightCount])
					rightCount += 1
			if leftCount == len(left) and rightCount < right(right):
				output.append(right[rightCount])
				rightCount += 1
			elif leftCount < len(left) and rightCount == len(right):
				output.append(left[leftCount])
				leftCount += 1
		return output

	def sort(self):
		temp = self.mergeSort(self.lst)
		self.lst = temp

	def show(self):
		return self.lst

if __name__ == "__main__":
	i = MergeSort([5,4,3,2,1])
	i.sort()
	print i.show()
