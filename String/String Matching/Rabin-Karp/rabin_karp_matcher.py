"""RABIN-KARP-MATCHER(T, P, d, q)
n = T.length
m = P.length
h = d^(m-1) mod q
p = 0
q = 0
t = 0
for i=1 to m
    p = (d*p + P[i]) mod q
    t = (d*t + T[i]) mod q
for s=0 to n-m
    if p==t
        if P[1..m] == T[s+1..s+m]
            print"Pattern occurs with shift" s
    if s < n-m
        t^(s+1) = (d(t - T[s+1]h) + T[s+m+1]) mod q"""


def rabin_karp_matcher(T, P, d, q):
    """Rabin Karp algorithm for string matching
    :T : input text
    :P : pattern to find
    :d : number of characters in the input text
    :q : prime number"""
    n = len(T)
    m = len(P)
    h = 1
    p = 0
    t = 0
    # preprocessing
    for i in range(m - 1):
        h = (h * d) % q
    for i in range(m):
        p = (d * p + ord(P[i])) % q
        t = (d * t + ord(T[i])) % q
    # string matching
    for s in range(n - m + 1):
        if p == t:
            for j in range(m):
                if T[s + j] != P[j]:
                    break
            j += 1
            if j == m:
                print("Pattern found at index: " + str(s))
        if s < n - m:
            t = (d * (t - ord(T[s]) * h) + ord(T[s + m])) % q
            if t < 0:  # for negative t
                t += q


text = "JUSTANANOTHERTEXT"
rabin_karp_matcher(text, "AN", len(text), 13)
