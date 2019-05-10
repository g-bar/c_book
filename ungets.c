/* Write a routine ungets(s) that will push back an entire string onto 
input. Should ungets know about buf and bugp, or should it just use
ungetch? */

/* ungets doesn't need to know about buf or bufp. It can just use ungetch */

#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) /* get a (possibly pushed-back) character */
{   
    return (bufp>0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (c == EOF){
        printf("error: cannot unget EOF");
    } else if (bufp >= BUFSIZE){
            printf("ungetch: too many characters\n");
    } else{
        buf[bufp++] = c;
    }
}

void ungets(char s[])
{
    int i;
    int len = strlen(s);
    if ( len > BUFSIZE - bufp){
        printf("ungets: too many characters, not enough space in buffer \n");
    }

    for (i=len-1; i >= 0; i-- ){
        ungetch(s[i]);
    }
}