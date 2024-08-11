#include <stdio.h>

void ft_rev_int_tab(int *tab, int size);

void print_array(int *arr, int size)
{
    int i;

    i = 0;
    while (i < size)
        printf("%d ", arr[i++]);
    printf("\n");
}

int main(void)
{
    int empty[0];
    int test_even[6] = {10, 20, 30, 40, 50, 60};
    int test_odd[7] = {5, 15, 25, 35, 45, 55, 65};

    ft_rev_int_tab(empty, 0);
    ft_rev_int_tab(test_even, 6);
    ft_rev_int_tab(test_odd, 7);
    print_array(empty, 0);
    print_array(test_even, 6);
    print_array(test_odd, 7);

    return 0;
}

