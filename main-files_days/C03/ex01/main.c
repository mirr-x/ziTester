#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int main() {
	char *str1 = (char *)"xxxxxx";
	char *str2 = (char *)"yyyyyy";
	printf("std: %i, yours: %i\n", strncmp(str1, str2, 20), ft_strncmp(str1, str2, 20));
	printf("std: %i, yours: %i\n", strncmp(str1, str2, 0), ft_strncmp(str1, str2, 0));
	printf("std: %i, yours: %i\n", strncmp(str1, str2, 1), ft_strncmp(str1, str2, 1));

	str1 = "abcadef";
	str2 = "abcad";
	printf("std: %i, yours: %i\n", strncmp(str1, str2, 5), ft_strncmp(str1, str2, 5));
	printf("std: %i, yours: %i\n", strncmp(str1, str2, 6), ft_strncmp(str1, str2, 6));

	str1 = "abcad";
	str2 = "abcadtg";
	printf("std: %i, yours: %i\n", strncmp(str1, str2, 5), ft_strncmp(str1, str2, 5));
	printf("std: %i, yours: %i\n", strncmp(str1, str2, 6), ft_strncmp(str1, str2, 6));
}
