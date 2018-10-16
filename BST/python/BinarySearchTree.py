# -*- coding: utf-8 -*-
"""
Created on Sun Oct 22 14:27:07 2017

@author: Daniel
"""


# Binary Search Tree for an array of a single type
class BST:
    def __init__(self, dataType):
        self._root = None
        self._dataType = dataType
        self._size = 0

    def loadArray(self, inputArray):
        self.arr = inputArray

    def getSize(self):
        return self._size

    def isEmpty(self):
        return self._size == 0

    def populateTree(self):
        for i in range(len(self.arr)):
            self.insert(self.arr[i])

    def insert(self, value):
        if type(value) == self._dataType:
            itemNum = self._size
            newNode = Node(value, type(value), itemNum, None, None, None)
            if (self._root is None):
                self._root = newNode
                self._size += 1
                return

            pointer = self._root
            currentVal = pointer.getData()
            while True:
                if value < currentVal:
                    if pointer.getLeft() is None:
                        newNode.setParent(pointer)
                        pointer.setLeft(newNode)
                        self._size += 1
                        return
                    else:
                        pointer = pointer.getLeft()
                        currentVal = pointer.getData()

                elif value > currentVal:
                    if pointer.getRight() is None:
                        newNode.setParent(pointer)
                        pointer.setRight(newNode)
                        self._size += 1
                        return
                    else:
                        pointer = pointer.getRight()
                        currentVal = pointer.getData()

                elif value == currentVal:
                    print("Value already exists in BST.")
                    return

    def search(self, value):
        if type(value) == self._dataType:
            if (self._root is None):
                return False

            pointer = self._root
            currentVal = pointer.getData()
            while True:
                if value < currentVal:
                    if pointer.getLeft() is None:
                        return False

                    pointer = pointer.getLeft()
                    currentVal = pointer.getData()

                elif value > currentVal:
                    if pointer.getRight() is None:
                        return False

                    pointer = pointer.getRight()
                    currentVal = pointer.getData()

                elif value == currentVal:
                    return pointer.getItemNum()

    def inOrderTraversal(self, node):
        if node is not None:
            self.inOrderTraversal(node.getLeft())
            self.sorted.append(node.getData())
            self.inOrderTraversal(node.getRight())

    def getSorted(self):
        self.sorted = list()
        self.inOrderTraversal(self._root)
        return self.sorted


class Node:
    def __init__(self, data, dataType, itemNum, parent, left, right):
        self._data = data
        self._dataType = dataType  # specifies type which node holds
        self._itemNum = itemNum  # position in parent array
        self._parent = parent  # link to parent node
        self._left = left  # link to left child node
        self._right = right  # link to right child node

    def getData(self):
        return self._data

    def setData(self, newData):
        if type(newData) == self._dataType:
            self._data = newData
        else:
            print("Error, wrong data type.")

    def getItemNum(self):
        return self._itemNum

    def getParent(self):
        return self._parent

    def setParent(self, newParent):
        self._parent = newParent

    def getLeft(self):
        return self._left

    def setLeft(self, newLeft):
        self._left = newLeft

    def getRight(self):
        return self._right

    def setRight(self, newRight):
        self._right = newRight


if __name__ == "__main__":
    bst = BST(int)
    bst.loadArray((11, 20, 18, 4, 5, 7, 2, 0))
    bst.populateTree()
    print(bst.search(18))
    print(bst.getSorted())
