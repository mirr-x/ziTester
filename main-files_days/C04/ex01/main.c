#include <string.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putstr(char *str);

int main() {
	ft_putstr("");
	write(1, "--\n", 3);
	ft_putstr("hola!\n");
	char s1[10] = "asdfKsfg";
	s1[3] = 90;
	ft_putstr(s1);
}