/*
 * K&R Sec. 5.3
 *
 * Assignment by array pointer
 * and print
 *
 */

#include <stdio.h>

int assign(int *a, int na);
int print_result(int *a, int na);

int main()
{
    int a[10], na;

    na = sizeof(a)/sizeof(a[0]);

    assign(a, na);
    print_result(a, na);
}

int assign(int *a, int na)
{
    int* pa = a;
    int i;

    for (i=0; i < na; i++) // pa is allowed to get out of array boundary
    {
        *pa = i;
        printf("a[%d], *pa = %d\n", i, *pa );
        pa++;
    }
}

int print_result(int *a, int na)
{
    int i;

    for (i=0; i < na; i++) // i<11 to get out is allowed and dangerous
        printf("a[%d] = %d\n", i, a[i]);
}

