def hamming_distance(s1, s2):
    """Returns the Hamming distance between two equal-length sequences"""
    if len(s1) != len(s2):
        raise ValueError("Sequences of unequal length")
    return sum(ch1 != ch2 for ch1, ch2 in zip(s1, s2))

if __name__ == "__main__":
    print hamming_distance("kittens", "kittens") # output is 0
    print hamming_distance("1011101 ", "1001001 ") # output is 2
    print hamming_distance("karolin", "kathrin") # output is 3
    try:
        print hamming_distance("1011101", "100100") # throws exception
    except ValueError as e:
        print e