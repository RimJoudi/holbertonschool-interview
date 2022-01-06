#!/usr/bin/python3
"""
minOperations module
"""


def minOperations(n):
    """
    a method that calculates the fewest number of operations 
    needed to result in exactly n H characters in the file.
    """
    p = 2
    num = 0
    if type(n) != int or n <= 1:
        return 0
    while n != 1:
        if n % p == 0:
            n = n / p
            num = num + p
        else:
            p = p + 1
    return int(num)
