#include <stdio.h>

void ft_ultimate_ft(int *********ptr);

int main(void)
{
    int z;
    int *ptrz1;
    int **ptrz2;
    int ***ptrz3;
    int ****ptrz4;
    int *****ptrz5;
    int ******ptrz6;
    int *******ptrz7;
    int ********ptrz8;
    int *********ptrz9;

    z = 786;
    ptrz1 = &z;
    ptrz2 = &ptrz1;
    ptrz3 = &ptrz2;
    ptrz4 = &ptrz3;
    ptrz5 = &ptrz4;
    ptrz6 = &ptrz5;
    ptrz7 = &ptrz6;
    ptrz8 = &ptrz7;
    ptrz9 = &ptrz8;
    ft_ultimate_ft(ptrz9);
    printf("%d\n", z);
    z = 990;
    printf("%d\n", z);
    ft_ultimate_ft(ptrz9);
    printf("%d", z);
}