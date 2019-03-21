def longest_palindrome(text):
    
    length = len(text)
    palindromes_lengths = [1] * length
    for fgap in range(1, length):
        pre = palindromes_lengths[fgap]
        for rgap in reversed(range(0, fgap)):
            tmp = palindromes_lengths[rgap]
            if text[fgap] == text[rgap]:
                if rgap + 1 > fgap - 1:
                    palindromes_lengths[rgap] = 2
                else:
                    palindromes_lengths[rgap] = 2 + pre
            else:
                palindromes_lengths[rgap] = max(palindromes_lengths[rgap + 1],
                                                palindromes_lengths[rgap])
            pre = tmp
    return palindromes_lengths[0]

def main():
    print(longest_palindrome('bbabcbcab')) 
    print(longest_palindrome('abbaab'))    
    print(longest_palindrome('opengenus')) 

if __name__ == '__main__':
    main()
