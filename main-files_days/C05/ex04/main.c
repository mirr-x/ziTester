#include <stdio.h>

int ft_fibonacci(int index);

int	main(void)
{
	printf("-1:%d\n", ft_fibonacci(-20));
	printf("-1:%d\n", ft_fibonacci(-1));
	printf("0:%d\n", ft_fibonacci(0));
	printf("1:%d\n", ft_fibonacci(1));
	printf("1:%d\n", ft_fibonacci(2));
	printf("2:%d\n", ft_fibonacci(3));
	printf("55:%d\n", ft_fibonacci(10));
	printf("6765:%d\n", ft_fibonacci(20));
}
