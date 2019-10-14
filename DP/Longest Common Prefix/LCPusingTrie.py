#LCP using Tries
#Just check where #of children is != 1

from collections import defaultdict as df

class Node:
    def __init__(self):
        self.children = df(int)
        self.isEnd = False

class Trie:
    def __init__(self):
        self.root = Node()

    def getIndex(self, ch):
        return ord(ch) - ord('a')

    def add(self, key):
        cr = self.root
        for lvl in key:
            index = self.getIndex(lvl)

            if not cr.children[index]:
                cr.children[index] = Node()

            cr = cr.children[index]

        cr.isEnd = True

    def lcp(self):
        lcp=[]
        cr = self.root

        while (len(cr.children) == 1 and cr.isEnd == False):
            key = cr.children.keys()
            lcp.append(chr(key[0] +ord('a')))
            cr = cr.children[key[0]]

        print ''.join(lcp)

if __name__ == '__main__':
    trie=Trie()
    keys=['geekser', 'geeks', 'ge', 'geezer']
    for i in keys:
        trie.add(i)
    trie.lcp()

#Output would be 'ge'
