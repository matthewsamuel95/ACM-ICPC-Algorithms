# Python program for Dijkstra's shortest path algorithm for adjacency list
# representation of graph
from collections import defaultdict
import sys


class Heap():
    def __init__(self):
        self.array = []
        self.size = 0
        self.pos = []

    def newMinHeapNode(self, v, dist):
        minHeapNode = [v, dist]
        return minHeapNode

    # A utility function to swap two nodes
    # of min heap. Needed for min heapify
    def swapMinHeapNode(self, a, b):
        t = self.array[a]
        self.array[a] = self.array[b]
        self.array[b] = t

    def minHeapify(self, idx):
        smallest = idx
        left = 2 * idx + 1
        right = 2 * idx + 2

        if left < self.size and self.array[left][1] < self.array[smallest][1]:
            smallest = left

        if right < self.size and self.array[right][1] \
                < self.array[smallest][1]:
            smallest = right

        if smallest != idx:

            # Swap positions
            self.pos[self.array[smallest][0]] = idx
            self.pos[self.array[idx][0]] = smallest

            self.swapMinHeapNode(smallest, idx)

            self.minHeapify(smallest)

    def extractMin(self):

        if self.isEmpty() is True:
            return

        root = self.array[0]

        lastNode = self.array[self.size - 1]
        self.array[0] = lastNode

        self.pos[lastNode[0]] = 0
        self.pos[root[0]] = self.size - 1

        self.size -= 1
        self.minHeapify(0)

        return root

    def isEmpty(self):
        return True if self.size == 0 else False

    def decreaseKey(self, v, dist):
        # Get the index of v in  heap array
        i = self.pos[v]
        self.array[i][1] = dist

        while i > 0 and self.array[i][1] < self.array[(i - 1) / 2][1]:
            # Swap this node with its parent
            self.pos[self.array[i][0]] = (i - 1) / 2
            self.pos[self.array[(i - 1) / 2][0]] = i
            self.swapMinHeapNode(i, (i - 1) / 2)

            # move to parent index
            i = (i - 1) / 2

    # A utility function to check if a given
    # vertex 'v' is in min heap or not
    def isInMinHeap(self, v):

        if self.pos[v] < self.size:
            return True
        return False


def printArr(dist, n):
    print("Vertex\tDistance from source")
    for i in range(n):
        print("%d\t\t%d" % (i, dist[i]))


class Graph():
    def __init__(self, V):
        self.V = V
        self.graph = defaultdict(list)

    def addEdge(self, src, dest, weight):

        newNode = [dest, weight]
        self.graph[src].insert(0, newNode)

        newNode = [src, weight]
        self.graph[dest].insert(0, newNode)

    def dijkstra(self, src):

        V = self.V  # Get the number of vertices in graph
        dist = []  # dist values used to pick minimum
        # weight edge in cut

        minHeap = Heap()

        for v in range(V):
            dist.append(sys.maxint)
            minHeap.array.append(minHeap.newMinHeapNode(v, dist[v]))
            minHeap.pos.append(v)

        minHeap.pos[src] = src
        dist[src] = 0
        minHeap.decreaseKey(src, dist[src])

        minHeap.size = V

        while minHeap.isEmpty() is False:

            newHeapNode = minHeap.extractMin()
            u = newHeapNode[0]

            for pCrawl in self.graph[u]:

                v = pCrawl[0]

                if minHeap.isInMinHeap(v) and dist[u] != sys.maxint and \
                   pCrawl[1] + dist[u] < dist[v]:
                    dist[v] = pCrawl[1] + dist[u]

                    minHeap.decreaseKey(v, dist[v])

        printArr(dist, V)


# Driver program to test the above functions
graph = Graph(9)
graph.addEdge(0, 1, 4)
graph.addEdge(0, 7, 8)
graph.addEdge(1, 2, 8)
graph.addEdge(1, 7, 11)
graph.addEdge(2, 3, 7)
graph.addEdge(2, 8, 2)
graph.addEdge(2, 5, 4)
graph.addEdge(3, 4, 9)
graph.addEdge(3, 5, 14)
graph.addEdge(4, 5, 10)
graph.addEdge(5, 6, 2)
graph.addEdge(6, 7, 1)
graph.addEdge(6, 8, 6)
graph.addEdge(7, 8, 7)
graph.dijkstra(0)
