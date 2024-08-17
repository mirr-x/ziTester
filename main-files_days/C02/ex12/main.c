#include <stdio.h>
#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	char src[0xFF + 10];
	int	i;

	i = 0;
	while (i <= 0xFF)
	{
		src[i] = i;
		i++;
	}
	src[i] = 0;

	i = 0;
	while (i < 30)
	{
		ft_print_memory((void *)src, i);
		i++;
	}

	ft_print_memory((void *)src, 0x101);
}
