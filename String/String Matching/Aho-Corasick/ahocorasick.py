import unittest
from collections import deque, defaultdict

class AhoCorasick:
    def __init__(self, keywords):
        self.state = 0
        self.built = False
        self.keywords = keywords
        self.num_nodes = 1

        # We use a defaultdict with default of 0 to handle
        #   the loop from node 0 to itself when unknown
        #   characters are given.
        self.goto = [defaultdict(int)]
        self.fail = [0]
        self.output = [set()]

    def build(self):
        # We begin by building the goto function
        for keyword in self.keywords:
            cur_node = 0
            for letter in keyword:
                # If a path exists for this part of the word, continue along it
                if letter in self.goto[cur_node]:
                    cur_node = self.goto[cur_node][letter]

                # Otherwise we need to create a new node
                else:
                    self.goto[cur_node][letter] = self.num_nodes
                    self.goto.append(defaultdict(int))
                    self.output.append(set())
                    cur_node = self.num_nodes
                    self.num_nodes += 1

            # Update the output with the full keyword
            self.output[cur_node] = set([keyword])

        # To create the fail function we need to iteratively move up the tree
        # starting with nodes that have depth 1, then 2, and so on

        # We initialise all nodes to fail to the root
        self.fail = [0 for _ in range(self.num_nodes)]

        # Fill the queue with nodes of depth 1
        queue = deque()
        for a, s in self.goto[0].items():
            queue.append(s)
            self.fail[s] = 0

        # Construct the fail function
        while len(queue) != 0:
            r = queue.popleft()
            for a, s in self.goto[r].items():
                queue.append(s)
                state = self.fail[r]

                # Fail back until we can move back up a chain
                while a not in self.goto[state] and state != 0:
                    state = self.fail[state]

                self.fail[s] = self.goto[state][a]

                # Update output for substrings, e.g. add "he" to output
                # in the same spot as where "she" ends
                self.output[s] = self.output[s].union(self.output[self.fail[s]])

        # Mark the graph as built
        self.built = True

    def search(self, corpus):
        if not self.built:
            raise Exception("You need to build the graph before searching corpuses.")

        cur_node = 0
        freqs = defaultdict(int)

        # Each letter corresponds to one state change
        for letter in corpus:
            # Fail back until we can move up a chain
            while letter not in self.goto[cur_node] and cur_node != 0:
                cur_node = self.fail[cur_node]

            cur_node = self.goto[cur_node][letter]

            # Record keywords at this point in our dictionary
            for keyword in self.output[cur_node]:
                freqs[keyword] += 1

        return freqs

class TestAhoCorasick(unittest.TestCase):
    def test_paper_example(self):
        corpus = 'ushers'
        keywords = ['he', 'she', 'his', 'hers']
        expected = {
            'he'  : 1,
            'hers': 1,
            'she' : 1,
        }

        ac = AhoCorasick(keywords)
        ac.build()
        actual = ac.search(corpus)

        self.assertEqual(actual, expected)

    def test_wikipedia_example(self):
        corpus = 'abccab'
        keywords = ['a', 'ab', 'bab', 'bc', 'bca', 'c', 'caa']
        expected = {
            'a' : 2,
            'ab': 2,
            'bc': 1,
            'c' : 2,
        }

        ac = AhoCorasick(keywords)
        ac.build()
        actual = ac.search(corpus)

        self.assertEqual(actual, expected)

    def test_simple_all_substrings(self):
        corpus = 'abc'
        keywords = ['a', 'b', 'c', 'ab', 'bc', 'abc']
        expected = {
            'a'  : 1,
            'b'  : 1,
            'c'  : 1,
            'ab' : 1,
            'bc' : 1,
            'abc': 1,
        }

        ac = AhoCorasick(keywords)
        ac.build()
        actual = ac.search(corpus)

        self.assertEqual(actual, expected)

    def test_nonalpha_chars(self):
        corpus = 'I think she said, "the quick brown dog jumps over the lazy dog", maybe!'
        keywords = ['the', 'dog', 'he']
        expected = {
            'the': 2,
            'dog': 2,
            'he' : 3,
        }

        ac = AhoCorasick(keywords)
        ac.build()
        actual = ac.search(corpus)

        self.assertEqual(actual, expected)

if __name__ == '__main__':
    unittest.main()
