/*
 * K&R Sec. 5.2
 * Swap 2 int
 */

#include <stdio.h>

void swap( int *a, int *b );
//void swap_WRONG( int a, int b );

void main()
{
    int a = 1;
    int b = 2;

    printf("Before swap, \n");
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    printf("&a = %d\n",&a);
    printf("&b = %d\n",&b);

    swap(&a, &b);

    printf("After swap, \n");
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    printf("&a = %d\n",&a);
    printf("&b = %d\n",&b);
}

void swap( int *a, int *b )
{
    // Correct way 
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void swap_WRONG( int a, int b )
{
    // WRONG way 
    int temp;


    printf("Entering swap_WRONG, \n");
    // Showing address change
    printf("&a = %d\n",&a); 
    printf("&b = %d\n",&b);

    temp = a;
    a = b;
    b = temp;
}



