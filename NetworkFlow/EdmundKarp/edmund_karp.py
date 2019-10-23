import decimal


def EdmondsKarp(E, C, s, t):
    """
    :param E: Adjacency Matrix
    :param C: Capacity Matrix
    :param s: Source
    :param t: Sink
    """
    n = len(C)
    flow = 0
    F = [[0 for y in range(n)] for x in range(n)]
    while True:
        P = [-1 for x in range(n)]
        P[s] = -2
        M = [0 for x in range(n)]
        M[s] = decimal.Decimal('Infinity')
        BFSq = []
        BFSq.append(s)
        pathFlow, P = BFSEK(E, C, s, t, F, P, M, BFSq)
        if pathFlow == 0:
            break
        flow = flow + pathFlow
        v = t
        while v != s:
            u = P[v]
            F[u][v] = F[u][v] + pathFlow
            F[v][u] = F[v][u] - pathFlow
            v = u
    return flow


def BFSEK(E, C, s, t, F, P, M, BFSq):
    while (len(BFSq) > 0):
        u = BFSq.pop(0)
        for v in E[u]:
            if C[u][v] - F[u][v] > 0 and P[v] == -1:
                P[v] = u
                M[v] = min(M[u], C[u][v] - F[u][v])
                if v != t:
                    BFSq.append(v)
                else:
                    return M[t], P
    return 0, P


if __name__ == "__main__":
    E = [[1, 2], [2, 3], [3], []]  # Adjacency Matrix
    C = [[0, 1000000, 1000000, 0], [0, 0, 1, 1000000], [0, 0, 0, 1000000],
         [0, 0, 0, 0]]  # Capacity Matrix
    s = 0  # Source
    t = 3  # Sink
    print(EdmondsKarp(E, C, s, t))
