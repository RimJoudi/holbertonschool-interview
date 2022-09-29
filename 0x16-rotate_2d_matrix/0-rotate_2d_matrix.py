#!/usr/bin/python3
"""
fn that rotates 2D matrix 90 degrees clockwise in place 
"""


def rotate_2d_matrix(matrix):
    """
    Rotates 2D NxN matrix 90 degrees clockwise in place
    """
    N = len(matrix)

    matrix_copy = []
    copy_row = 0
    for column in range(N):
        for row in range((N - 1), -1, -1):
            if column is 0:
                matrix_copy.append([])
            matrix_copy[copy_row].append(matrix[row][column])
        copy_row += 1

    for row in range(N):
        for column in range(N):
            matrix[row][column] = matrix_copy[row][column]
