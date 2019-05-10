#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <constants.h>

char *line=NULL;
size_t n;
ssize_t chars;

/* getop: get next character or numeric operand */
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
