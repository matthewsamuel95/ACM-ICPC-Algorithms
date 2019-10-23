#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def last_digit_of(a,b):
    """ Calculates the last digit of a^b
    Args: 
        a (int): Base of a^b
        b (int): Exponent of a^b
    Returns:
        (int): The last digit of a^b
    """
    
    last_digit_a = int(str(a)[-1])
    
    if b % 4 == 0:
        exp = 4
    else:
        exp = b % 4
    
    return (last_digit_a ** exp) % 10