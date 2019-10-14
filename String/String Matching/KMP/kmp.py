#!/usr/bin/env python2.7
def get_kmp(xs):
    res = [-1, 0]
    cur = 0
    for i in range(2, len(xs) + 1):
        while cur >= 0 and xs[cur] != xs[i - 1]:
            cur = res[cur]
        cur += 1
        res.append(cur)
    return res

def find_pattern(text, pattern):
    kmp = get_kmp(pattern + ' ' + text)
    return [i for i in range(len(text) - len(pattern) + 1)
            if kmp[i + len(pattern) * 2 + 1] == len(pattern)]


if __name__ == '__main__':
    text = raw_input("Input text: ")
    pattern = raw_input("Input pattern: ")
    print "Pattern appears at starting indices: ", find_pattern(text, pattern)
