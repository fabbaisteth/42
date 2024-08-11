#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ft_check_conditions()
{
}

void input(char *input_string)
{
    int i;
    int input_length = (int)strlen(input_string);

    // Check if the input length is valid
    if (input_length > 32)
    {
        printf("Error: Input is too long. Maximum length is 32.\n");
        return;
    }

    int array_length = 0;
    i = 0;
    // Count the number of valid numbers in the input string
    while (i < input_length)
    {
        if (input_string[i] >= '1' && input_string[i] <= '4')
        {
            array_length++;
        }
        i++;
    }
    if (array_length != 16)
    {
        printf("Error: Invalid input. Input must contain 16 numbers.\n");
        return;
    }
    // Allocate memory for the array
    int *numbers_array = (int *)malloc(array_length * sizeof(int));

    // Sort the numbers into the array
    int index = 0;
    i = 0;
    while (i < input_length)
    {
        if (input_string[i] >= '1' && input_string[i] <= '4')
        {
            numbers_array[index] = input_string[i] - '0';
            index++;
        }
        i++;
    }

    for (int i = 0; i < array_length; i++)
    {
        printf("%d ", numbers_array[i]);
    }
    printf("\n");

    free(numbers_array);
}

int main()
{

    input("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2");

    return 0;
}