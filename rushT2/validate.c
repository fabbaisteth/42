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

int check_row(int *row, int left_view, int right_view)
{
    int temp_row[4];
    int j = 0;
    while (j < 4)
    {
        temp_row[j] = row[3 - j];
        j++;
    }
    return check_view(row, left_view) && check_view(temp_row, right_view);
}

int check_column(int **numbers_array, int col_index, int up_view, int down_view)
{
    int temp_col[4];
    int j = 0;
    while (j < 4)
    {
        temp_col[j] = numbers_array[j][col_index];
        j++;
    }

    if (!check_view(temp_col, up_view))
        return 0;

    j = 0;
    while (j < 4)
    {
        temp_col[j] = numbers_array[3 - j][col_index];
        j++;
    }

    return check_view(temp_col, down_view);
}

int validate_solution(int **numbers_array, int *views)
{
    int i = 0;
    while (i < 4)
    {
        if (!check_row(numbers_array[i], views[8 + i], views[12 + i]))
            return 0;

        if (!check_column(numbers_array, i, views[i], views[4 + i]))
            return 0;

        i++;
    }
    return 1;
}
