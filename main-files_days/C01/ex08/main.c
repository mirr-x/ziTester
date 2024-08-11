#include <stdio.h>
#include <stdlib.h>

void ft_sort_int_tab(int *tab, int size);

void swapppp(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *arr, int size)
{
    int i;

    i = 0;
    while (i < size)
        printf("%d ", arr[i++]);
    printf("\n");
}

void shuffle_array(int *arr, int size)
{
    int counter;

    counter = 0;
    while (counter < size * 5)
    {
        swapppp(&arr[rand() % size], &arr[rand() % size]);
        counter++;
    }
}

void populate_array(int *arr, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        arr[i] = (i + 2) * 3; // Changed to multiples of 3 starting from 6
        i++;
    }
    shuffle_array(arr, size);
}

int main(void)
{
    int empty[0];
    int test_even[8];
    int test_odd[9];
    int test_lots[50];

    populate_array(test_even, 8);
    populate_array(test_odd, 9);
    populate_array(test_lots, 50);
    ft_sort_int_tab(empty, 0);
    ft_sort_int_tab(test_even, 8);
    ft_sort_int_tab(test_odd, 9);
    ft_sort_int_tab(test_lots, 50);
    print_array(empty, 0);
    print_array(test_even, 8);
    print_array(test_odd, 9);
    print_array(test_lots, 50);

    return 0;
}

