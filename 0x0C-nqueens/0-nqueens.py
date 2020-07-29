#!/usr/bin/python3

""" Solve the NQueens problem """

from sys import argv


def position(queen, column):
    """checks if the position of each queen is valid"""
    for i in range(column):
        if queen[i] == queen[column]:
            return False
        if abs(queen[i] - queen[column]) == abs(i - column):
            return False
    return True


def placeQueen(queen, col):
    """ Recursive Function that change the queen """

    lng = len(queen)
    succ = 0

    if col == lng:
        res = []

        for i in range(len(queen)):
            res.append([i, queen[i]])

        print(res)
        return True

    queen[col] = -1

    while(queen[col] < lng - 1 or succ == 1):
        queen[col] = queen[col] + 1
        if position(queen, col):
            if col != lng:
                placeQueen(queen, (col + 1))
            else:
                succ = 1
                break
    return True


if __name__ == '__main__':

    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    if not argv[1].isnumeric():
        print("N must be a number")
        exit(1)

    length = int(argv[1])

    if length < 4:
        print("N must be at least 4")
        exit(1)

    board = [[0 for y in range(length)] for x in range(length)]
    response = placeQueen(board, 0)
