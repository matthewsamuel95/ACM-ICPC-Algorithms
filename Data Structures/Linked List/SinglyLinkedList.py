class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def traverse(self):
        node = head
        while node is not None:
            print(node.data)
            node = node.next


if __name__ == '__main__':
    n = int(input("Number of nodes: "))
    head_value = int(input("Enter value of head node: "))
    head = prev_node = Node(head_value)
    for i in range(2, n + 1):
        data = int(input("Enter value {}: ".format(i)))
        new_node = Node(data)
        prev_node.next = new_node
        prev_node = new_node

    print("\nTraversing Nodes")
    head.traverse()
