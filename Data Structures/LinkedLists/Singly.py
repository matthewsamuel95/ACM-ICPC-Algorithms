class Node:

   def __init__(self,data,nextNode=None):
       self.data = data
       self.nextNode = nextNode

   def getData(self):
       return self.data

   def setData(self,val):
       self.data = val

   def getNextNode(self):
       return self.nextNode

   def setNextNode(self,val):
       self.nextNode = val

class LinkedList:

   def __init__(self,head = None):
       self.head = head
       self.size = 0

   def getSize(self):
       return self.size

   def addNode(self,data):
       newNode = Node(data,self.head)
       self.head = newNode
       self.size+=1
       return True
       
   def printNode(self):
       curr = self.head
       while curr:
           print(curr.data)
           curr = curr.getNextNode()

myList = LinkedList()
print "Inserting Nodes"
print(myList.addNode(7))
print(myList.addNode(18))
print(myList.addNode(27))
print "Printing Nodes"
myList.printNode()
print "Getting Size of the Linked List"
print(myList.getSize())
