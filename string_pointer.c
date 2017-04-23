/*
 * K&R Sec. 5.3
 *
 * String as character arrays,
 * loop by pointer and subscription is also the same.
 *
 */

#include <stdio.h>

int putstr(char *s);
int putstr_sub(char *s);

int main()
{
    char *s = "Running.";

    putstr(s);
    putstr_sub(s);
}

int putstr(char *s)
{
    printf("Loop by pointer:\n");

    while (*s != '\0') 
    {
        putchar(*s);
        printf("\n");
        *s++;
    }
}

int putstr_sub(char *s)
{
    int i;

    printf("Loop by subscript:\n");

    for (i=0; s[i] != '\0'; i++ ) 
    {
        putchar(s[i]);
        printf("\n");
    }
}
