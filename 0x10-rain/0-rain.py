#!/usr/bin/python3
""" this module has the method rain """


def rain(walls):
    """ Finds the amount of rain retained
    between walls of different heights"""

    if (len(walls) <= 0):
        return (0)
    rain = 0

    for i in range(1, len(walls) - 1):
        height_left = walls[i]
        for j in range(i):
            height_left = max(height_left, walls[j])

        height_right = walls[i]
        for j in range(i + 1, len(walls)):
            height_right = max(height_right, walls[j])
        rain = rain + (min(height_left, height_right) - walls[i])

    return (rain)
