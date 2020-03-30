#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <constants.h>
#include <sys/types.h>

/* getop: get next character or numeric operand */
int getop(char s[])
{
    static char *line = NULL;
    size_t n = 0;
    ssize_t chars;

    int i = 0;
    int c;

    if (line == NULL)
    {
        chars = getline(&line, &n, stdin);
    }

    if (chars == -1)
    {
        free(line);
        line = NULL;
        return EOF;
    }

    for (; (s[0] = c = *line) == ' ' || c == '\t'; line++)
        ;
    s[1] = '\0';

    if (c == '\n')
    {
        line = NULL;
        return c;
    }

    if (isalpha(c))
    {
        for (line++; isalpha(s[++i] = c = *line); line++)
            ;

        s[i] = '\0';
        return i == 1 ? s[0] : COMMAND;
    }

    if (!isdigit(c) && c != '.')
    {
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
