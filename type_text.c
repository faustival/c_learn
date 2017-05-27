/*
 * K&R Sec. 5.4, allocation of char array by pointer arithmetic
 *
 * Modified to be a LIFO implementation of a toy text editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define textsize 10000


static char text[textsize];
static char buf[20];
static char *ptr_eof = text;
static char *ptr_eof_old = text;

int get_modebuf();
void print_options();
void write_words();
void print_text();
void del_str();
int first_int();

int main()
{
    int c;

    print_options();
    while ( (c = get_modebuf()) != 'q' )
    {
        switch (c)
        {
            case 'h':
                print_options();
                break;
            case 'a':
                write_words();
                break;
            case 'd':
                del_str( first_int() );
                break;
            case 'p':
                print_text();
                break;
        }
    }
    print_text();
}

int get_modebuf() /* appropriatly use scanf() instead */
{
    char *s;
    int c;

    for ( s = buf ; (c = getchar()) != '\n' ; s++ )
        *s = c;
    *s = '\0';
    return buf[0];
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
    printf("\n Press Ctrl-D to quit append mode.\n");
    ptr_eof_old = ptr_eof;
    while ( (c = getchar()) != EOF )
    {
        *ptr_eof = c;
        ptr_eof++;
    }
    printf("\n Meet EOF, type next operation. \n");
}

void undo_write()
{
    ptr_eof = ptr_eof_old;
}

void del_str(int n)
{
    printf( "Delete %d characters.\n", n);
    ptr_eof -= n;
    *ptr_eof = '\0';
}

void print_text()
{
    printf(text);
}

int first_int()
/* get the first int (continuous digits) from string */
{
    char *s;
    char *s_int;
    char intbuf[20];
    int n;

    s_int = intbuf;
    for ( s = buf ; !isdigit(*s) ; s++ )
        continue;
    for ( s_int = intbuf ; isdigit(*s) ; s++ )
    {
        *s_int = *s;
        s_int++;
    }
    *s_int = '\0'; 
    n = atoi(intbuf);
    return n;
}

