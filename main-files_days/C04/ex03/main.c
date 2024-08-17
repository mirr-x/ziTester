#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	ft_atoi(char *str);

int main() {
	printf("%i\n", ft_atoi("\t\n\v\f\r      23"));
	printf("%i\n", ft_atoi("     ------+++++---12341"));
	printf("%i\n", ft_atoi("     ------+++++---123413"));
	printf("%i\n", ft_atoi("00000000002147483647"));
	printf("%i\n", ft_atoi("-2147483648"));
	printf("%i\n", ft_atoi("a"));
}