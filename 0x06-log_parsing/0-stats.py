#!/usr/bin/python3
'''
Write a script that reads stdin line by line and computes metrics:
Input format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
After every 10 lines and/or a keyboard interruption (CTRL + C),
print these statistics from the beginning:
    Total file size: File size: <total size>
    where <total size> is the sum of all previous <file size>
    (see input format above)
    Number of lines by status code:
        possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
        if a status code doesn’t appear, don’t print anything for this
        status code
        format: <status code>: <number>
        status codes should be printed in ascending order
'''
import sys


def print_status(size, status):
    '''
    Print the status
    '''
    print('File size: {}'.format(size))
    for key, value in sorted(status.items()):
        if value:
            print('{}: {}'.format(key, value))


if __name__ == '__main__':
    size, count = 0, 0
    status = {'200': 0, '301': 0, '400': 0, '401': 0,
              '403': 0, '404': 0, '405': 0, '500': 0}
    try:
        for line in sys.stdin:
            args = line.split()
            if len(args) > 2:
                if args[-2] in status:
                    status[args[-2]] += 1
                size += int(args[-1])
            count += 1
            if not count % 10:
                print_status(size, status)
    except KeyboardInterrupt:
        pass
    finally:
        print_status(size, status)