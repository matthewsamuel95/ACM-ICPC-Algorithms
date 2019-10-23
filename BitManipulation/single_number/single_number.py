def single_number(numbers):
    single = 0

    for number in numbers:
        single ^= number

    return single


if __name__ == "__main__":
    numbers = [3, 4, 2, 1, 3, 1, 4]
    assert single_number(numbers) == 2
    numbers = input("Enter list of repeated numbers: ")
    numbers = map(int, numbers.split())
    print(single_number(numbers))

