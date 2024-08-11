#include "input.h"
#include "solver.h"
#include "print_solution.h"
#include "utils.h"
#include <stdlib.h>

int main()
{
    int **numbers_array;
    int *views;
    int row = 0, col = 0;

    views = input("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2");
    numbers_array = allocate_array();
    if (!numbers_array)
        return 1;

    if (solve(numbers_array, row, col, views))
        print_solution(numbers_array);
    else
        putstr("No solution found\n");

    for (int i = 0; i < 4; i++)
    {
        free(numbers_array[i]);
    }
    free(numbers_array);
    free(views);

    return 0;
}
