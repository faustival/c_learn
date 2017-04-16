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

int main()
{
    int i, stat, arry[SIZE];
    int n_int = 0;
    //char inpfname[] = "int_inpf.log";
    //inpf = fopen(inpfname, "r");
    inpf = stdin;

    for (i=0; i < SIZE && (stat = getint(&arry[i], &n_int, inpf)) != EOF; i++)
    {
        if (stat == 0) // for the strange char in getint()
            i--;
        //printf("i = %d, arry[i] = %d, buf = %s\n", i, arry[i], buf);
    }
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

    /* Expect before integer digits */
    while(isspace(c = getch(inpf)))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        //ungetch(c);  // what is this used for in K&R ?
        return 0; //EOF;  
        /* return 0 for outer call to determine
         * better return EOF for the strange chars
         */
    }
    /* Expect beginning reading */
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch(inpf);
    for (*pn = 0; isdigit(c); c = getch(inpf))
        *pn = 10 * *pn + (c - '0');
    /* Pass back valid value */
    *pn *= sign;
    ++(*n_int);
    /* Expect to be invalid char after integer,
     * Push back 
     */
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



