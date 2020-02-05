#!/usr/bin/python3
"""
    Determine wether all boxes can be unlocked by other boxes' values
    @boxes: 2d array of boxes with values inside them
    Returns: True or False
"""


def canUnlockAll(boxes):

    if len(boxes) == 0:
        return True

    stack = [0]
    unlocked = [False] * len(boxes)
    unlocked[0] = True

    while stack:
        for key in boxes[stack.pop()]:
            if key > 0 and key < len(boxes) and not unlocked[key]:
                unlocked[key] = True
                stack.append(key)

    return all(unlocked)
