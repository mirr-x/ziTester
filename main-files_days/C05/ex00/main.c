#include <stdio.h>

int ft_iterative_factorial(int nb);

int	main(void)
{
	printf("0:%d\n", ft_iterative_factorial(-10));
	printf("0:%d\n", ft_iterative_factorial(-1));
	printf("1:%d\n", ft_iterative_factorial(0));
	printf("1:%d\n", ft_iterative_factorial(1));
	printf("3628800:%d\n", ft_iterative_factorial(10));
	printf("6:%d\n", ft_iterative_factorial(3));
}
