#!/usr/bin/python3
'''
In a text file, there is a single character H. Your text editor can execute only two operations in this file: Copy All and Paste. Given a number n, write a method that calculates the fewest number of operations needed to result in exactly n H characters in the file.
'''
def minOperations(n):

    if n < 2:
        return 0
    prime, sum = 2, 0
    while prime <= n / 2:
        if n % prime == 0:
            n //= prime
            sum += prime
        else:
            prime += 1
    return sum + n