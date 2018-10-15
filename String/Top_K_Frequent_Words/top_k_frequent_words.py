# Returns k number of words sorted on their occurrence
def top_k_frequent_words(words, k: int):
    return sorted(
        sorted(set(words)), key=lambda x: words.count(x), reverse=True)[:k]


if __name__ == '__main__':
    inpt = input('Enter space seperated words: ').split()
    k = int(
        input(
            'Enter the amount of words to retreive based on their occurance: ')
    )
    print(top_k_frequent_words(inpt, k))
