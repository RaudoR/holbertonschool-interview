#!/usr/bin/python3
'''
Write a script that reads stdin line by line and computes metrics
'''
import sys


def print_status(size, status):
    
    print('File size: {}'.format(size))
    for key, value in sorted(status.items()):
        print('{}: {}'.format(key, value))


if __name__ == '__main__':
    size, count = 0, 0
    status = {}
    try:
        for line in sys.stdin:
            args = line.split()
            if args[7] in status:
                status[args[7]] += 1
            else:
                status[args[7]] = 1
            size += int(args[8])
            count += 1
            if not count % 10:
                print_status(size, status)
    finally:
        print_status(size, status)