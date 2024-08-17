#include <ctype.h>
#include <stdio.h>
#include <string.h>

char	*ft_strlowcase(char *str);

int main(void)
{
	char str[100] = "ABDSDF-sdfsdf,,sdfYU74rff;";
	char cpy[100];
	char *ret;
	strcpy(cpy, str);

	printf("\"%s\": %s\n", str, ft_strlowcase(cpy));

	ret = ft_strlowcase(cpy);
	printf("Same string returned? %i\n", ret == cpy);
}
