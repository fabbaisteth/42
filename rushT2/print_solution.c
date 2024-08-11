#include "print_solution.h"
#include "utils.h"

void print_solution(int **solution)
{
    int i = 0;
    while (i < 4)
    {
        int j = 0;
        while (j < 4)
        {
            ptch(solution[i][j] + '0');
            if (j < 3)
                ptch(' ');
            j++;
        }
        ptch('\n');
        i++;
    }
}
