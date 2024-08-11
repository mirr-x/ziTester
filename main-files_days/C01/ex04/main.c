#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b);

int main(void)
{
    int a;
    int b;

    a = 123;
    b = 10;
    ft_ultimate_div_mod(&a, &b);
    printf("%d %d\n", a, b);

    a = -123;
    b = 15;
    ft_ultimate_div_mod(&a, &b);
    printf("%d %d\n", a, b);

    // Changing values
    a = 456;
    b = 20;
    ft_ultimate_div_mod(&a, &b);
    printf("%d %d\n", a, b);

    a = -456;
    b = 25;
    ft_ultimate_div_mod(&a, &b);
    printf("%d %d\n", a, b);

    return 0;
}
