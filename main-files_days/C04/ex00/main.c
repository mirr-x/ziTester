#include <stdio.h>

int ft_strlen(char *str);

int main(void)
{
	// Test cases
	printf("%d\n", ft_strlen("Hello, World!"));
	printf("%d\n", ft_strlen("42 School"));
	printf("%d\n", ft_strlen(""));
	printf("%d\n", ft_strlen("1234567890"));
	printf("%d\n", ft_strlen("a"));
	printf("%d\n", ft_strlen("The quick brown fox jumps over the lazy dog"));
	printf("%d\n", ft_strlen("Lorem ipsum dolor sit amet"));
	printf("%d\n", ft_strlen("C programming"));
	printf("%d\n", ft_strlen("abcdefghijklmnopqrstuvwxyz"));
	printf("%d\n", ft_strlen("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	printf("%d\n", ft_strlen("1234567890abcdefghijklmnopqrstuvwxyz"));
	printf("%d\n", ft_strlen("Special characters! @#^&*()"));
	printf("%d\n", ft_strlen("Whitespace   "));
	printf("%d\n", ft_strlen("Tabs\tand\nnewlines"));
	printf("%d\n", ft_strlen("Long string with multiple lines\nSecond line\nThird line"));
	printf("%d\n", ft_strlen("Numbers 12345"));
	printf("%d\n", ft_strlen("Symbols !@#$%^&*()"));
	printf("%d\n", ft_strlen("Empty space "));
	printf("%d\n", ft_strlen("Line1\nLine2\nLine3"));
	printf("%d\n", ft_strlen("Testing with unicode characters: üñîçødë"));
	printf("%d\n", ft_strlen("Edge case: Very long string which will be cut off for brevity"));
	printf("%d\n", ft_strlen("Another example with a bit more text"));
	printf("%d\n", ft_strlen("A very simple test"));
	printf("%d\n", ft_strlen("Final test case here"));

	return 0;
}
