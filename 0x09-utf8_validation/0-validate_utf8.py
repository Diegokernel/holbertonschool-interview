#!/usr/bin/python3
"""
0. UTF-8 Validation
"""


def validUTF8(data):
    """ Checks if data is a valid utf-8 """

    number_bytes = 0
    for ele in data:
        ele = format(ele, '#010b')[-8:]
        if number_bytes != 0:
            number_bytes -= 1
            if not ele.startswith('10'):
                return False
        elif ele[0] == '1':
            number_bytes = len(ele.split('0')[0])
            if number_bytes == 1 or number_bytes > 4:
                return False
            number_bytes -= 1

    return True if number_bytes == 0 else False
