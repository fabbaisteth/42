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
