#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	printf("\"abz\": %i\n", ft_str_is_lowercase("abz"));
	printf("\"ab{\": %i\n", ft_str_is_lowercase("ab{"));
	printf("\"ab`\": %i\n", ft_str_is_lowercase("ab`"));
	printf("\"\": %i\n", ft_str_is_lowercase(""));
	printf("\"asdasda..\": %i\n", ft_str_is_lowercase("asdasda.."));
	printf("\"asdasAa\": %i\n", ft_str_is_lowercase("asdasAa"));
}
