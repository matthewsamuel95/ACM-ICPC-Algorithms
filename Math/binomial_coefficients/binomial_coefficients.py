# Complexity: O(n^2)
# Computes the lines of Pascal's triangle.
# Pascal's triangle gives us result of binom(n,p), which is equivalent to combination(n,p).

import fileinput

binomial_coefficients = []
line = []
line.append(1)
binomial_coefficients.append(line)

# Element at line x and column y(binom[x][y]) of Pascal's triangle can be calculated as (binom[x-1][y] + binom[x-1][y-1]).
def precomp(n):
    for i in range(1,n):
        line = []
        line.append(1)

        for j in range(1,i):
            line.append(binomial_coefficients[i - 1][j] + binomial_coefficients[i - 1][j - 1])

        line.append(1)

        binomial_coefficients.append(line)

precomp(40)

for line in fileinput.input():
    n,p = line.strip().split()
    n = int(n)
    p = int(p)

    print(binomial_coefficients[n][p])

