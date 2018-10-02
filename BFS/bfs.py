import collections


def bfs(graph, root): 
    visited, queue = set(), collections.deque([root])
    while queue: 
        vertex = queue.popleft()
        for neighbour in graph[vertex]: 
            if neighbour not in visited: 
                visited.add(neighbour) 
                queue.append(neighbour) 


if __name__ == '__main__':
    # sample input format below
    graph = {0: [1, 2], 1: [2], 2: []} 
    bfs(graph, 0)
