class QuickSort:
    def __init__(self, lst):
        self.lst = lst

    def partition(self, left, right):
        pivot = self.lst[right]
        i = left

        for j in range(left, right):
            if self.lst[j] < pivot:
                self.lst[i],self.lst[j] = self.lst[j],self.lst[i]
                i += 1

        self.lst[i],self.lst[right] = self.lst[right],self.lst[i]
        return i
        
    def sortHelper(self, left, right):
        if right > left:
            index = self.partition(left, right)
            self.sortHelper(left, index-1)
            self.sortHelper(index+1, right)

    def sort(self):
        self.sortHelper(0, len(self.lst)-1)


    def show(self):
        return self.lst

if __name__ == "__main__":
    i = QuickSort([0,5,5,4,6,3,5,8,2,1])
    i.sort()
    print i.show()
