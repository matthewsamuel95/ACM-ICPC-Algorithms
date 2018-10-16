def is_anagram(a: str, b: str):
    count = [0 for _ in range(26)]
    count2 = [0 for _ in range(26)]
    a_length, b_length = len(a), len(b)

    if a_length != b_length:
        return False

    for i in range(a_length):
        if 'a' <= a[i] <= 'z':
            count[ord(a[i]) - ord('a')] += 1
        elif 'A' <= a[i] <= 'Z':
            count2[ord(a[i]) - ord('A')] += 1
        if 'a' <= b[i] <= 'z':
            count[ord(b[i]) - ord('a')] -= 1
        elif 'A' <= b[i] <= 'Z':
            count2[ord(b[i]) - ord('A')] -= 1

    if any(count) or any(count2):
        return False

    return True


if __name__ == '__main__':
    a, b = 'Abc', 'cab'
    if is_anagram(a, b):
        print('Anagrams')
    else:
        print('Not Anagrams')
