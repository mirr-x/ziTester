#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	printf("\"ABZ\": %i\n", ft_str_is_uppercase("ABZ"));
	printf("\"AB@\": %i\n", ft_str_is_uppercase("AB@"));
	printf("\"AB[\": %i\n", ft_str_is_uppercase("AB["));
	printf("\"\": %i\n", ft_str_is_uppercase(""));
	printf("\"DASFJET..\": %i\n", ft_str_is_uppercase("ADASFJET.."));
}
