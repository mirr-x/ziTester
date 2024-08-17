#include <stdio.h>

int	ft_str_is_alpha(char *str);

int main(void)
{
	printf("\"abcde\": %i\n", ft_str_is_alpha("abcde"));
	printf("\"\": %i\n", ft_str_is_alpha(""));
	printf("\"23bcQHasda1d\": %i\n", ft_str_is_alpha("23bcQHasda1d"));
}
