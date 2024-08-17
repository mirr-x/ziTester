#include <ctype.h>
#include <stdio.h>
#include <string.h>

char	*ft_strcapitalize(char *str);

int main(void)
{
	char str[100] = "salut, comMent tu vas ? 42mots quarAnte-deux; cinquante+et+uN e.puntOs";
	char cpy[100];
	char *ret;
	strcpy(cpy, str);

	printf("%s\n", ft_strcapitalize(cpy));

	ret = ft_strcapitalize(cpy);
	printf("Same string returned? %i\n", ret == cpy);
}
