#include <ctype.h>
#include <stdio.h>
#include <string.h>

char	*ft_strupcase(char *str);

int main(void)
{
	char str[100] = "abcd-fsdAfddsSS";
	char cpy[100];
	char *ret;
	strcpy(cpy, str);

	printf("\"%s\": %s\n", str, ft_strupcase(cpy));

	ret = ft_strupcase(cpy);
	printf("Same string returned? %i\n", ret == cpy);
}
