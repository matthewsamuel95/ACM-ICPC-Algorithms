
def primefactors(number):
    interm_res = []
    a =2
    while(a<=number):
        if(number%a == 0):
            number = number//a
            interm_res.append(a)
        else:
            a+=1
    d = {k:interm_res.count(k) for k in interm_res}
    result = [(k,v) for k,v in d.items()]
    return result


def factorize_number(number):
    l = []
    if(number == 1):
        return l
    elif number<0:
        raise ValueError
    elif(isinstance(number,int) == False):
        raise TypeError
    else:
        l = primefactors(number)
        return l


# you are given the tests here according to the spec, usually you will have to write these yourself from the spec!
def test_factorize_number():
    assert [] == factorize_number(1)
    assert [(2, 1)] == factorize_number(2)
    assert [(2, 1), (5, 1), (601, 1)] == factorize_number(6010)
    assert [(5, 2), (7, 1)] == factorize_number(175)
    assert [(2, 1), (7919, 4)] == factorize_number(7865228921869442)
    try:
        factorize_number(-3)
        assert False, "negative number did not throw"
    except ValueError as ve:
        pass

    try:
        factorize_number(2.3)
        assert False, "float did not throw"
    except TypeError as te:
        pass
