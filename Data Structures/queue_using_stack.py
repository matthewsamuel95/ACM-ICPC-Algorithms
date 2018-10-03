'''
    - Stack is a linear data structure which follows a particular order in which the operations are performed
    - The order may be LIFO(Last In First Out) or FILO(First In Last Out)
    - Stack operations:
        - Push O(1)
        - Pop O(1)
        - Empty O(1)
        - Peek O(1)
'''

class UnderflowException(Exception):
    pass

class Stack(object):
    def __init__(self):
        self._stack = []
        self.__top = -1

    def __str__(self):
        return ', '.join([str(i) for i in self._stack])

    def push(self, element):
        '''
            :param element: data element to be pushed onto stack
        '''
        self._stack.append(element)
        self.__top += 1
        return

    def pop(self):
        '''
            pops the topmost element from stack
        '''
        if not self.is_empty():
            self.__top -= 1
            value = self._stack[self.__top + 1]
            del self._stack[self.__top + 1]
            return value
        else:
            raise UnderflowException

    def is_empty(self):
        '''
            returns True if stack is empty else returns false
        '''
        return len(self._stack) == 0

    def peek(self):
        '''
            returns the top element from the stack
        '''
        if self.is_empty():
            return -1
        return self._stack[self.__top]
        
'''
    Algorithm:
        - First we pop all the elements from stack one and store them in stack two
        - Once stack one is empty we push the current element in the stack one
        - We then again pop all the elements from stack two and push them back in stack one
        - This way, the element that is entered currently will occupy the last element in the stack
        - Time complexity of this operation is O(n) and dequeue will be O(1)
        - Same can be done with dequeue, in that case time complexity of enqueue will be O(1)
'''

class QueueUsingStack(object):
    def __init__(self):
        self._stack_one = Stack()
        self._stack_two = Stack()
    
    def __str__(self):
        return self._stack_one.__str__()
    
    def enqueue(self, element):
        '''
            :param element: element to be enqueued in the queue
        '''
        while not self._stack_one.is_empty():
            self._stack_two.push(self._stack_one.pop())
        
        self._stack_one.push(element)

        while not self._stack_two.is_empty():
            self._stack_one.push(self._stack_two.pop())
        return

    def dequeue(self):
        if self._stack_one.is_empty():
            raise UnderflowException
        return self._stack_one.pop()

if __name__ == '__main__':
    queue = QueueUsingStack()
    for i in range(10):
        queue.enqueue(i)
    print(queue)
    print(queue.dequeue())
    print(queue.dequeue())
    print(queue)
