#!/usr/bin/python3
"""
Given a list of non-negative integers representing the heights of walls
with unit width 1, as if viewing the cross-section of a relief map,
calculate how many square units of water will be retained after it rains.
"""


def rain(walls):
    """
    walls: a list of non-negative integers.
    Return: Integer indicating total amount of rainwater retained.
    """
    retained_water = 0

    for i in range(1, len(walls) - 1):

        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        retained_water += (min(left, right) - walls[i])

    return retained_water
