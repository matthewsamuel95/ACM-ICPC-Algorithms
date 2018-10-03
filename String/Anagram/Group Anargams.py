#!/bin/python3
import sys
from collections import defaultdict

fstd="test1"
sys.stdin = open('%s.txt' % fstd, 'r')
input = sys.stdin.readline

def solve(words):
    d=defaultdict(list)
    for w in words:
        d["".join(sorted(w))].append(w)
    return list(d.values())

if __name__ == "__main__":
    print("Input comma separated list of words")
    words = [s.strip() for s in input().split(",")]
    #words=["eat", "tea", "tan", "ate", "nat", "bat"]
    print("[")
    res=solve(words)
    for r in res:
        print("  {}".format(r))
    print("]")
