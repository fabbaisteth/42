#include <unistd.h>
#include <stdlib.h>
#include "input.h"
#include "utils.h"
#include <stdio.h>

int *input(char *input_string)
{
    char *err = "Error";
    int num;
    int k = 0;
    int *views;

    views = (int *)malloc(16 * sizeof(int));
    if (!views)
        return 0;
    while (*input_string)
    {
        if (*input_string >= '1' && *input_string <= '4')
        {
            num = *input_string - '0';
            if (k < 16)
            {
                views[k] = num;
                printf("%d\n", views[k]);
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

    if (k != 16)
    {
        putstr(err);
        free(views);
        return 0;
    }
    return views;
}