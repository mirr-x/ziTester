#include <stdio.h>

void ft_ft(int *ptr);

int main(void)
{
    int xs;

    xs = 6756;
    ft_ft(&xs);
    printf("%d\n", xs);
    xs = 562;
    printf("%d\n", xs);
    ft_ft(&xs);
    printf("%d", xs);
}