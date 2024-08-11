#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

    // Check if exactly 16 numbers were parsed
    if (k != 16)
    {
        putstr(err);
        free(views);
        return 0;
    }
    return views;
}

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
    int left_view, right_view, up_view, down_view;

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

int validate_solution(int **numbers_array, int *views)
{
    int i;
    int temp_row[4];
    int temp_col[4];

    // Check all rows
    for (i = 0; i < 4; i++)
    {
        if (!check_view(numbers_array[i], views[8 + i])) // Left view
            return 0;
        int j = 0;
        while (j < 4)
        {
            temp_row[j] = numbers_array[i][3 - j];
            temp_col[j] = numbers_array[j][i];
            j++;
        }
        if (!check_view(temp_row, views[12 + i])) // Right view
            return 0;
        if (!check_view(temp_col, views[i])) // Up view
            return 0;
        j = 0;
        while (j < 4)
        {
            temp_col[j] = numbers_array[3 - j][i];
            j++;
        }
        if (!check_view(temp_col, views[4 + i])) // Down view
            return 0;
    }
    return 1;
}

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
                return (1);
            input_array[row][col] = 0;
        }
        i++;
    }
    return (0);
}

void print_solution(int **solution)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ptch(solution[i][j] + '0');
            if (j < 3)
                ptch(' ');
        }
        ptch('\n');
    }
}

int main()
{
    int **numbers_array;
    int *views;
    int row = 0,
        col = 0;

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