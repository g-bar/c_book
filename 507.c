#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t MAXLEN = 1000;
size_t MAXLINES = 100000;

/* readlines: read input lines */
int readlines(char **lineptr, char *p)
{
    int len, nlines;
    char *line;
    nlines = 0;
    line = malloc(MAXLEN);
    while ((len = getline(&line, &MAXLEN, stdin)) > 0)
    {

        if (nlines >= MAXLINES)
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
        p += len;
    }

    return nlines;
}

int main()
{
    int nlines;
    char *lineptr = malloc(MAXLINES);
    char p[1000000];
    /* number of input lines read */
    if ((nlines = readlines(&lineptr, p)) >= 0)
    {
        return 0;
    }

    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}
