def is_anagram(str1, str2):
    """Checks if two strings are anagrams of each other"""

    #Convert strings into lists
    #Also convert all letters to lower case for consistency
    #purposes
    l1 = list(str1.lower())
    l2 = list(str2.lower())

    #Sort both strings and see if they are the same
    if l1.sort() == l2.sort():
        return True
    else:
        return False
