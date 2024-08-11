#ifndef VALIDATE_H
#define VALIDATE_H

int check_view(int *line, int expected_view);
int is_valid(int **numbers_array, int row, int col, int num, int *views);
int validate_solution(int **numbers_array, int *views);

#endif /* VALIDATE_H */
