class Trienode:
	def __init__(self):
		self.ch=[None]*26
		self.endofword=None
class Tries:
	def __init__(self):
		self.head=None
	def findkey(self,x):
		if ord(x)>=97 and ord(x)<=122:
			return ord(x)-97
		if ord(x)>=65 and ord(x)<=90:
			return ord(x)-65

	def add(self,s):
		if self.head==None:
			self.head=Trienode()
		tmp=self.head.ch
		for i in range(len(s)):
			key=self.findkey(s[i])
			if tmp[key]==None:
				tmp[key]=Trienode()
			if i!=len(s)-1:
				tmp=tmp[key].ch
			else:
				tmp[key].endofword='#'
	def search(self,s):
		if self.head==None:
			print("Not Found")
		else:
			tmp=self.head.ch
			for i in range(len(s)):
				key=self.findkey(s[i])
				if tmp[key]==None:
					print("Not found")
					return
				else:
					tempo=tmp
					tmp=tmp[key].ch
			if tempo[key].endofword=='#':
				print("FOUND")
			else:
				print("Not Found")
t=Tries()
t.add("apple")
t.add("ball")
t.search("apple")
