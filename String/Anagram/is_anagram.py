def is_anagram(a: str, b: str):
    a, b = a.lower(), b.lower()
    count = [0 for _ in range(26)]
    a_length, b_length = len(a), len(b)

    if a_length != b_length:
        return False

    for i in range(a_length):
        if 'a' <= a[i] <= 'z':
            count[ord(a[i]) - ord('a')] += 1
        if 'a' <= b[i] <= 'z':
            count[ord(b[i]) - ord('a')] -= 1

    if any(count):
        return False

    return True


if __name__ == '__main__':
    a, b = 'Abc', 'cab'
    if is_anagram(a, b):
        print('Anagrams')
    else:
        print('Not Anagrams')
