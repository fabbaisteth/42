#include "print_solution.h"
#include "utils.h"

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
