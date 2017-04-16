/*
 * K&R Sec. 5.2
 *
 * Still get buggy for pattern like "19e".
 *
 * Uncomment inpf = stdin;
 *
 * write the file int_inpf.log:
 *     19  -12 8  -1 8
 *     end
 *
 * and test with:
 *     getint.exc < int_inpf.log
 */

#include <stdio.h>
#include <ctype.h>

#define SIZE 100
#define BUFSIZE 100

int getint(int *pn, int *n_int, FILE *inpf);
int getch(FILE *inpf);
void ungetch(int c);

char buf[BUFSIZE];
int bufp = 0;
FILE *inpf;

void main()
{
    int i,  arry[SIZE];
    int n_int = 0;
    char inpfname[] = "int_inpf.log";
    inpf = fopen(inpfname, "r");
    //inpf = stdin;

    for (i=0; i < SIZE && getint(&arry[i], &n_int, inpf) != EOF; i++)
        printf("i = %d, arry[i] = %d, buf = %s\n", i, arry[i], buf);
    n_int = i;
    fclose(inpf);
    printf("%d integers obtained:\n", n_int);
    for (i=0; i < n_int; i++)
    {
        printf("%d\n", arry[i]);
    }
}

int getint(int *pn, int *n_int, FILE *inpf)
{
    int c, sign;

    while(isspace(c = getch(inpf)))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        //ungetch(c);
        return -1;  // better match EOF = -1 here
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch(inpf);
    for (*pn = 0; isdigit(c); c = getch(inpf))
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    ++(*n_int);
    if (c != EOF)
        ungetch(c);
    return c;
}

/*
 * getch() and ungetch() : cooperating functions from K&R Sec. 4.3
 */

int getch(FILE *inpf)
{
    return (bufp > 0) ? buf[--bufp] : fgetc(inpf);
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("  ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}



