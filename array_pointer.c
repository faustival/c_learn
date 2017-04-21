/*
 * K&R Sec. 5.3
 *
 * Assignment by array pointer
 * and print
 *
 */

#include <stdio.h>

int assign(int *a);
int print_result(int *a);

int main()
{
    int a[10];

    assign(a);
    print_result(a);
}

int assign(int *a)
{
    int* pa = a;

    a[0] = 0;
    while (pa < (a+9)) // use pa is easy to get out of array boundary
    {
        pa++;
        *pa = *(pa-1) + 1;
        printf("pa = %d, *pa = %d, *(pa-1) = %d\n", pa, *pa, *(pa-1));
    }
}

int print_result(int *a)
{
    int i;

    for (i=0; i<10; i++) // i<11 to get out is allowed and dangerous
        printf("a[%d] = %d\n", i, a[i]);
}

