#include <stdio.h>

int ft_find_next_prime(int nb);

int	main(void)
{
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
		ft_find_next_prime(-1) == 2 ? "OK" : "Fail",
		ft_find_next_prime(-3) == 2 ? "OK" : "Fail",
		ft_find_next_prime(0) == 2 ? "OK" : "Fail",
		ft_find_next_prime(1) == 2 ? "OK" : "Fail",
		ft_find_next_prime(2) == 2 ? "OK" : "Fail",
		ft_find_next_prime(3) == 3 ? "OK" : "Fail",
		ft_find_next_prime(4) == 5 ? "OK" : "Fail",
		ft_find_next_prime(5) == 5 ? "OK" : "Fail",
		ft_find_next_prime(6) == 7 ? "OK" : "Fail",
		ft_find_next_prime(7) == 7 ? "OK" : "Fail",
		ft_find_next_prime(10) == 11 ? "OK" : "Fail",
		ft_find_next_prime(11) == 11 ? "OK" : "Fail",
		ft_find_next_prime(13) == 13 ? "OK" : "Fail",
		ft_find_next_prime(19) == 19 ? "OK" : "Fail",
		ft_find_next_prime(20) == 23 ? "OK" : "Fail"
		  );
}
