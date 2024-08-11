#include <unistd.h>
#include <stdlib.h>
#include "input.h"
#include "utils.h"
#include <stdio.h>

int *allocate_views()
{
    int *views = (int *)malloc(16 * sizeof(int));
    if (!views)
    {
        putstr("Error");
        return NULL;
    }
    return views;
}

int parse_input(char *input_string, int *views)
{
    int num, k = 0;

    while (*input_string)
    {
        if (*input_string >= '1' && *input_string <= '4')
        {
            num = *input_string - '0';
            if (k < 16)
            {
                views[k] = num;
                k++;
            }
        }
        else if (*input_string != ' ')
        {
            putstr("Error");
            return 0;
        }
        input_string++;
    }
    return k;
}

int validate_views(int k)
{
    if (k != 16)
    {
        putstr("Error");
        return 0;
    }
    return 1;
}

int *input(char *input_string)
{
    int *views = allocate_views();
    if (!views)
        return NULL;

    int k = parse_input(input_string, views);
    if (!k || !validate_views(k))
    {
        free(views);
        return NULL;
    }

    return views;
}
