#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <constants.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */

char *line=NULL;
size_t n;
ssize_t chars;


int getop(char s[])
{
    int i=0;
    int c;
    n = 0;
    
    if (line == NULL){
        chars = getline(&line, &n,stdin);
    }

    if (chars == -1){
        free(line);
        line=NULL;
        return EOF;
    }

    for (; (s[0] = c = *line) == ' ' || c == '\t'; line++ )
        ;
    s[1] = '\0';

    if (c == '\n'){
        line=NULL;
        return c;
    } 
    
    if (isalpha(c)){
        for (line++; isalpha(s[++i] = c = *line); line++)
            ;
        
        s[i] = '\0';
        return i==1 ? s[0] : COMMAND;
    }

    if (!isdigit(c) && c != '.'){
        line++;
        return c; /* not a number */
    }
    
    if (isdigit(c)) /* collect integer part */
        for (line++; isdigit(s[++i] = c = *line); line++)
            ;
    if (c == '.') /* collect fraction part */
        for (line++; isdigit(s[++i] = c = *line); line++)
            ;
    s[i] = '\0';
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