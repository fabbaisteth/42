#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

void ptch(char c)
{
    write(1, &c, 1);
}

void putstr(char *str)
{
    while (*str)
    {
        ptch(*str);
        str++;
    }
}

int **allocate_array()
{
    int **numbers_array;
    int i, j;

    // Allocate memory for the 4x4 array
    numbers_array = (int **)malloc(4 * sizeof(int *));
    if (!numbers_array)
        return 0;
    i = 0;
    while (i < 4)
    {
        numbers_array[i] = (int *)malloc(4 * sizeof(int));
        if (!numbers_array[i])
            return 0;
        j = 0;
        while (j < 4)
        {
            numbers_array[i][j] = 0; // Initialize the grid to zero
            j++;
        }
        i++;
    }
    return numbers_array;
}
