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
        return 0;
    }
    return views;
}

int validate_input_sequence(char *input_string)
{
    int last_was_space = 0;

    while (*input_string)
    {
        if (*input_string >= '1' && *input_string <= '4')
            last_was_space = 0;
        else if (*input_string == ' ')
            last_was_space = 1;
        else
        {
            if (last_was_space)
            {
                putstr("Error");
                return 0;
            }
            putstr("Error");
            return 0;
        }
        input_string++;
    }
    return 1;
}

int parse_input(char *input_string, int *views)
{
    int k = 0;

    while (*input_string && k < 16)
    {
        if (*input_string >= '1' && *input_string <= '4')
        {
            views[k++] = *input_string - '0';
        }
        input_string++;
    }
    return k;
}

int validate_input(int k, int *views)
{
    if (k != 16)
    {
        putstr("Error");
        free(views);
        return 0;
    }
    return 1;
}

int *input(char *input_string)
{
    if (!validate_input_sequence(input_string))
        return 0;

    int *views = allocate_views();
    if (!views)
        return 0;

    int k = parse_input(input_string, views);
    if (!k || !validate_input(k, views))
    {
        free(views);
        return 0;
    }
    return views;
}