#!/usr/bin/python3
"""Find minimum number of operations to create string with COPY & PASTE"""


def minOperations(n):
    """a method that calculates the fewest number of operations
    needed to result in exactly n H characters in the file.'"""
    operations = 0
    if n <= 1:
        return operations

    for i in range(2, int(n ** 1/2 + 1)):
        while n % i == 0:
            operations += i
            n //= i

    if n > 1:
        operations += n
    return operations
