/*
 * K&R Sec. 1.5
 * Check the result with:
 *     ./cat_wc.exc < somefile > writefile
 *     wc -l file
 *     wc -m file
 *     wc -w file
 */

#include <stdio.h>

#define on 1
#define off 0

void cat_wc();

int main()
{
    cat_wc();
}

void cat_wc()
{ // could be a simple version of Linux cat, wc
    int c;
    int trigger;
    long nchar, nline, nword;

    nchar = nline = nword = 0;
    trigger = off;
    while ( (c = getchar()) != EOF )
    {
        putchar(c);
        //fflush(stdout);
        //printf("%ld\n", c);
        if (c == '\n')
            ++nline;
        if (c == '\n' || c == ' ' || c == '\t')
            trigger = off;
        else
            if (trigger == off)
            {
                ++nword;
                trigger = on;
            }
        ++nchar;
    }
    printf("N_line, %ld\n", nline);
    printf("N_char, %ld\n", nchar);
    printf("N_word, %ld\n", nword);
}



