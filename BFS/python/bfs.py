from collections import defaultdict


class Graph():
    def __init__(self, numberOfNode):
        self.graph = defaultdict(list)
        self.visited = [False] * numberOfNode

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def BFS(self, node):
        queue = []
        queue.append(node)
        self.visited[node] = True

        while queue:
            currentNode = queue.pop(0)
            print(currentNode)

            children = self.graph[currentNode]
            for i in range(len(children)):
                if not self.visited[children[i]]:
                    queue.append(children[i])
                    self.visited[children[i]] = True


if __name__ == '__main__':
    graph = Graph(5)

    # Add edges to vertex 0, 1, 2, 3 and 4
    graph.addEdge(0, 1)
    graph.addEdge(0, 3)
    graph.addEdge(1, 2)
    graph.addEdge(1, 3)
    graph.addEdge(2, 1)
    graph.addEdge(2, 3)
    graph.addEdge(3, 1)
    graph.addEdge(3, 2)
    graph.addEdge(3, 4)

    print("Breadth First Search starting from vertex 0:")
    graph.BFS(0)
