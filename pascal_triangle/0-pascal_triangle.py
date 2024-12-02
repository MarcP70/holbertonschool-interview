#!/usr/bin/python3
"""
0-pascal_triangle
"""


def pascal_triangle(n):
    if (n <= 0):
        return ([])

    t = [([1] * (i + 1)) for i in range(n)]

    for i in range(1, n):
        for j in range(1, i):
            t[i][j] = t[i - 1][j - 1] + t[i - 1][j]

    return (t)
