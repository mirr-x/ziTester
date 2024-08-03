#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod);

int main(void)
{
    int a;
    int b;
    int div;
    int mod;

    a = 765;
    b = 24;
    ft_div_mod(a, b, &div, &mod);
    printf("%d %d %d %d\n", a, b, div, mod);
    a = -454;
    b = 46;
    ft_div_mod(a, b, &div, &mod);
    printf("%d %d %d %d\n", a, b, div, mod);
}