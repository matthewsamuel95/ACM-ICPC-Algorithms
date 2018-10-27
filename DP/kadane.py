#!/usr/bin/python3
"""
This module contains an implementation of Kadane's algorithm to determine the
maximum sum of a subarray.

Doctests included. Please use docstring as example to use algorithm.
"""


def kadane(list_obj=None):
    """
    Find maximum sum of a subarray

    :param list list_int: list of objs
    :return: maximum sum of subarray
    :rtype: int

    DOCTESTS
    --------
    Test 1 (list of ints):
    >>> print(kadane([-1, 2, 3, -4, 5, -6]))
    6

    Test 2 (list of ints):
    >>> print(kadane([-1, 2, 3, -6, 5, -6]))
    5

    Test 3 (list of ints):
    >>> print(kadane([3, 2, 3, -7, 5, -6]))
    11

    Test 4 (invalid argument type):
    >>> print(kadane())
    Traceback (most recent call last):
        ...
    TypeError: input must be of type list

    Test 5 (empty list):
    >>> print(kadane([]))
    Traceback (most recent call last):
        ...
    ValueError: list must not be empty
    """
    
    if type(list_obj) is not list:
        raise TypeError("input must be of type list")
    if not list_obj:
        raise ValueError("list must not be empty")
    max_sum, cur_max = list_obj[0], list_obj[0]
    size = len(list_obj)

    for idx, val in enumerate(list_obj):
        cur_max = max(val, val + cur_max)
        max_sum = max(max_sum, cur_max)

    return max_sum

if __name__ == '__main__':
    import doctest
    doctest.testmod()
