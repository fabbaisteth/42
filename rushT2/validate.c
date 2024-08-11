#include "validate.h"

int check_view(int *line, int expected_view)
{
    int max_seen = 0;
    int count = 0;
    int i = 0;

    while (i < 4)
    {
        if (line[i] > max_seen)
        {
            max_seen = line[i];
            count++;
        }
        i++;
    }

    return (count == expected_view);
}

int is_valid(int **numbers_array, int row, int col, int num, int *views)
{
    int i;

    // Check for duplicate numbers in the same row and column
    i = 0;
    while (i < 4)
    {
        if (numbers_array[row][i] == num || numbers_array[i][col] == num)
            return 0;
        i++;
    }
    return 1;
}

int check_all_views(int *row, int *col, int *views, int i)
{
    if (!check_view(row, views[12 + i])) // Right view
        return 0;
    if (!check_view(col, views[i])) // Up view
        return 0;

    for (int j = 0; j < 4; j++)
        col[j] = row[3 - j];

    if (!check_view(col, views[4 + i])) // Down view
        return 0;

    return 1;
}

int validate_row_col(int **numbers_array, int *views, int i)
{
    int temp_row[4];
    int temp_col[4];

    for (int j = 0; j < 4; j++)
    {
        temp_row[j] = numbers_array[i][3 - j];
        temp_col[j] = numbers_array[j][i];
    }

    if (!check_view(numbers_array[i], views[8 + i])) // Left view
        return 0;

    return check_all_views(temp_row, temp_col, views, i);
}

int validate_solution(int **numbers_array, int *views)
{
    for (int i = 0; i < 4; i++)
    {
        if (!validate_row_col(numbers_array, views, i))
            return 0;
    }
    return 1;
}
