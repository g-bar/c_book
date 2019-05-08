#include <stdio.h>
#include <ctype.h>
#include <constants.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (isalpha(c)){
        while (isalpha(s[++i] = c = getch()))
            ;
        if (c != EOF){
            ungetch(c);
            s[i] = '\0';
        }
        return i==1 ? s[0] : COMMAND;
    }

    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
        ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
        ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}


char buf = '\0';

int getch(void) /* get a (possibly pushed-back) character */
{
    int val = (buf != '\0') ? buf : getchar();
    buf = '\0';
    return val;
}

void ungetch(int c) /* push character back on input */
{
    if (c == EOF){
        printf("error: cannot unget EOF");
    }
    buf = c;
}


/* Write a routine ungets(s) that will push back an entire string onto 
input. Should ungets know about buf and bugp, or should it just use
ungetch? */

/* ungets doesn't need to know about buf or bufp. It can just use ungetch */

void ungets(char s[])
{
    int i;
    for (i=0; s[i] != '\0'; i++ ){
        ungetch(s[i]);
    }
}