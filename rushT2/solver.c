#include "solver.h"
#include "validate.h"

int solve(int **input_array, int row, int col, int *views)
{
    int i = 1;
    if (row == 4)
        return validate_solution(input_array, views);
    if (col == 4)
        return (solve(input_array, row + 1, 0, views));
    if (input_array[row][col] != 0)
        return (solve(input_array, row, col + 1, views));
    while (i <= 4)
    {
        if (is_valid(input_array, row, col, i, views))
        {
            input_array[row][col] = i;
            if (solve(input_array, row, col + 1, views))
                return 1;
            input_array[row][col] = 0;
        }
        i++;
    }
    return 0;
}
