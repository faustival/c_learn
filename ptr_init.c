/*
 * K&R Sec. 5.1
 * Showing pointers initialization  
 */

#include <stdio.h>

void ptr_init();
void ptr_null();

int main()
{
    ptr_init();
}

void ptr_init()
{
    int a = 1986;
    int *p = &a;
    printf( "Value of a: %d\n ", a);
    printf( "Address of a: %d\n ", &a);
    printf( "Address of a by pointer value: %d\n ", p);
    printf( "Address of pointer: %d\n ", &p);
    printf( "Value of a by pointer dereferencing: %d\n ", *p);
}

void ptr_null()
{
    int *p = NULL;
    
    printf( "Variable NULL pointer is printed as: %d\n", p);
    printf( "Dereference NULL pointer is printed as\n: " );
    printf( "%d\n", *p);
}
