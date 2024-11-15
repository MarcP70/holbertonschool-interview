#!/usr/bin/python3
"""
Module to calculate the perimeter of an island in a grid.

The grid is represented as a list of lists of integers:
- 0 represents water
- 1 represents land
Each cell is square with a side length of 1. Cells are connected
horizontally or vertically (not diagonally). The grid is completely
surrounded by water, and there is only one island or no island at all.
The island doesn’t have “lakes” (water inside that isn’t connected
to the water surrounding the island).
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    Parameters:
    grid (List[List[int]]): A list of lists where 0 represents water and
                            1 represents land.

    Returns:
    int: The perimeter of the island.

    The function works by iterating over each cell in the grid. Each land cell
    (represented by a 1) starts by contributing 4 to the perimeter. If the land
    cell has a neighbor above or to the left, it means they share a side, and
    we subtract 2 from the total perimeter for each shared side.
    """
    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    # Iterate over each cell in the grid
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                # Each land cell initially contributes 4 to the perimeter
                perimeter += 4

                # If there is a neighboring land cell above, subtract 2
                if r > 0 and grid[r - 1][c] == 1:
                    perimeter -= 2

                # If there is a neighboring land cell to the left, subtract 2
                if c > 0 and grid[r][c - 1] == 1:
                    perimeter -= 2

    return perimeter
