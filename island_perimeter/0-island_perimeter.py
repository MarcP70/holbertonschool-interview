def island_perimeter(grid):
    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                # Start with 4 sides for each land cell
                perimeter += 4

                # Check the cell above
                if r > 0 and grid[r - 1][c] == 1:
                    perimeter -= 2

                # Check the cell to the left
                if c > 0 and grid[r][c - 1] == 1:
                    perimeter -= 2

    return perimeter
