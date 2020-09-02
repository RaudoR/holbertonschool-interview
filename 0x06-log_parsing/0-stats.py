#!/usr/bin/python3
""" Write a script that reads stdin line by line and computes metrics """

if __name__ == '__main__':
    import sys

    fileSize, counter = 0, 0

    stats = {"200": 0, "301": 0, "400": 0, "401": 0,
             "403": 0, "404": 0, "405": 0, "500": 0}

    def report(stats, fileSize):
        print("File size: {:d}".format(fileSize))
        for i in sorted(stats.keys()):
            if stats[i] != 0:
                print("{}: {:d}".format(i, stats[i]))

    try:
        for line in sys.stdin:
            if counter != 0 and counter % 10 == 0:
                report(stats, fileSize)
            strline = line.split()
            counter += 1
            try:
                fileSize += int(strline[-1])
            except:
                pass
            try:
                if strline[-2] in stats:
                    stats[strline[-2]] += 1
            except:
                pass
        report(stats, fileSize)
    except KeyboardInterrupt:
        report(stats, fileSize)
        raise