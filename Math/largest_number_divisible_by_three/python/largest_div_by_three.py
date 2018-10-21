def largest_div_by_three(number):
    digits = [int(x) for x in list("{}".format(number))]
    digits.sort()
    sumOfDigits = sum(digits)
    if sumOfDigits % 3 == 0:
        try:
            return int(''.join(map(str, digits))[::-1])
        except ValueError:
            return 0
    if sumOfDigits % 3 == 1:
        for i in xrange(len(digits)):
            if digits[i] % 3 == 1:
                del digits[i]
                try:
                    return int(''.join(map(str, digits))[::-1])
                except ValueError:
                    return 0
        removal_count = []
        for i in xrange(len(digits)):
            if digits[i] % 3 == 2:
                removal_count.append(i)
                if len(removal_count) == 2:
                    copy = digits[:]
                    del copy[removal_count[1]]
                    del copy[removal_count[0]]
                    try:
                        return int(''.join(map(str, copy))[::-1])
                    except ValueError:
                        return 0
        return 0
    for i in xrange(len(digits)):
        # pr
        if digits[i] % 3 == 2:
            digits.pop(i)
            try:
                return int(''.join(map(str, digits))[::-1])
            except ValueError:
                return 0
    removal_count = []
    for i in xrange(len(digits)):
        if digits[i] % 3 == 1:
            removal_count.append(i)
            if len(removal_count) == 2:
                copy = digits[:]
                del copy[removal_count[1]]
                del copy[removal_count[0]]
                try:
                    return int(''.join(map(str, copy))[::-1])
                except ValueError:
                    return 0

ans = 0
for count in xrange(0, 1000):
    ans += largest_div_by_three(count)
print ans #258417
