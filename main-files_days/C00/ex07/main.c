#include <limits.h>
#include <unistd.h>
#include <stdio.h>

void ft_putnbr(int nb);

int main(void)
{
    ft_putnbr(42);
    write(1, "\n", 1);
    ft_putnbr(-99);
    write(1, "\n", 1);
    ft_putnbr(7);
    write(1, "\n", 1);
    ft_putnbr(-456);
    write(1, "\n", 1);
    ft_putnbr(INT_MAX);
    write(1, "\n", 1);
    ft_putnbr(INT_MIN);
    return (0);
}
