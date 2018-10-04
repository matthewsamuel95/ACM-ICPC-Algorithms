def is_anagram(str1, str2):
    """Checks if two strings are anagrams of each other"""

    #Get a count of all the characters in each string
    chars1 = get_alphabet(str1.lower())
    chars2 = get_alphabet(str2.lower())

    #Check if both strings contain the same characters in the same amounts
    if chars1 == chars2:
        return True
    else:
        return False

def get_alphabet(string):
    """Creates a dictionary containing a count of the number of times
    each alphanumeric character in string is used."""

    """E.g. get_alphabet("Hello") would return {'H':1, 'e':1, 'l':2, 'o':1}"""
    alphabet = dict()
    for c in string:
        if c.isalnum():
            if c in alphabet:
                alphabet[c] = alphabet[c] + 1
            else:
                alphabet[c] = 1

    return alphabet

