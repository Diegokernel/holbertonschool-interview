#!/usr/bin/python3
''' reads stdin line by line and computes metrics '''

if __name__ == '__main__':
    import sys

    file_size, count = [0], 1
    codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

    def print_stats():
        """print stats"""
        print("File size: {}".format(file_size[0]))
        for m in sorted(codes.keys()):
            if codes[m] != 0:
                print("{}: {}".format(m, codes[m]))

    try:
        for line in sys.stdin:
            try:
                data = line.split()
                file_size[0] += int(data[-1])
                code = int(data[-2])
                if code in codes:
                    codes[code] += 1
            except BaseException:
                pass
            if count % 10 == 0:
                print_stats()
            count += 1
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
