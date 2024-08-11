#include "print_solution.h"
#include <stdlib.h>

int *input(char *input_string)
{
    char *err = "Error";
    int num;
    int k = 0;
    int *views;

    views = (int *)malloc(16 * sizeof(int));
    if (!views)
        return 0;
    // Parse the input string
    while (*input_string)
    {
        if (*input_string >= '1' && *input_string <= '4')
        {
            num = *input_string - '0';
            // printf("%d\n", num);
            if (k < 16) // First 16 numbers are for views
            {
                views[k] = num;
                k++;
            }
        }
        else if (*input_string != ' ')
        {
            putstr(err);
            free(views);
            return 0;
        }
        input_string++;
    }

    // Check if exactly 16 numbers were parsed
    if (k != 16)
    {
        putstr(err);
        free(views);
        return 0;
    }
    return views;
}