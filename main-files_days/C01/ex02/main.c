#include <stdio.h>

void ft_swap(int *a, int *b);

int main(void)
{
    int a;
    int b;

    a = 986;
    b = 43;
    ft_swap(&a, &b);
    printf("%d %d\n", a, b);
    a = -45;
    b = 36;
    ft_swap(&a, &b);
    printf("%d %d\n", a, b);
}