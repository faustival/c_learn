/*
 * K&R Sec. 5.4
 *
 * Modified to be a LIFO implementation of a toy text editor.
 */

#include <stdio.h>

#define textsize 10000


static char text[textsize];
static char *ptr_eof = text;
static char *ptr_eof_old = text;

void print_options();
void write_words();
void print_text();

int main()
{
    int c, ichar;
    char buf[100];
    char *s;

    print_options();
    while(1)
    {
        /* read keywords */ 
        for ( s = buf ; (c = getchar()) != '\n' ; s++ )
            *s = c;
        *s = '\0';
        /* entering corresponding edit mode */
        if ( buf[0] == 'h' )
            print_options();
        else if ( buf[0] == 'a' )
            write_words();
        else if ( buf[0] == 'p' )
            print_text();
        else if ( buf[0] == 'q' )
            break;
    }
    print_text();
}

void print_options()
{
    printf("\n Select operations: \
            \n [h]elp, print this, \
            \n [a]ppend, \
            \n [u]ndo, \
            \n [d]el characters, ([d]{int}), \
            \n [p]rint current text status, \
            \n [q]uit. \
            \n");
}

void write_words()
{
    int c;
    printf("Press Ctrl-D to quit append mode.\n \n");
    ptr_eof_old = ptr_eof;
    while ( (c = getchar()) != EOF )
    {
        *ptr_eof = c;
        ptr_eof++;
    }
}

void undo_write()
{
    ptr_eof = ptr_eof_old;
}

void del_str(int n)
{
    ptr_eof -= n;
}

void print_text()
{
    printf(text);
}

