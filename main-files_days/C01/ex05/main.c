#include <unistd.h>

void ft_putstr(char *str);

int main(void)
{
    ft_putstr("hello");
    write(1, "\n", 1);
    ft_putstr("holla\noutro");
    return 0;
}

