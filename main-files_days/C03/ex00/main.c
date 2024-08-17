#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int main() {
	char *str0 = "";
	printf("std: %i, yours: %i\n", strcmp(str0, "a"), ft_strcmp(str0, "a"));

	char *str1 = (char *)"abcadef";
	char *str2 = (char *)"abcadef";
	printf("std: %i, yours: %i\n", strcmp(str1, str2), ft_strcmp(str1, str2));

	str1 = "abcadef";
	str2 = "abcad";
	printf("std: %i, yours: %i\n", strcmp(str1, str2), ft_strcmp(str1, str2));

	str1 = "abcad";
	str2 = "abcadtg";
	printf("std: %i, yours: %i\n", strcmp(str1, str2), ft_strcmp(str1, str2));
}