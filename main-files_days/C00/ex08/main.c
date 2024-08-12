#include <limits.h>
#include <unistd.h>

void ft_print_combn(int n);

int main(void)
{
    ft_print_combn(3);
    write(1, "\n", 1);
    ft_print_combn(4);
    write(1, "\n", 1);
    ft_print_combn(5);
    write(1, "\n", 1);
    ft_print_combn(6);
    write(1, "\n", 1);
    ft_print_combn(7);
    write(1, "\n", 1);
    ft_print_combn(8);
    write(1, "\n", 1);
    ft_print_combn(9);
    write(1, "\n", 1);
    ft_print_combn(10);
    write(1, "\n", 1);
    ft_print_combn(2);
    return (0);
}
