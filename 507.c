#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t MAXLEN = 10000;
size_t MAXLINES = 10000000;

/* readlines: read input lines */
int readlines(char **lineptr)
{
    int len, nlines;
    nlines = 0;
    char *line = malloc(MAXLEN);
    while ((len = getline(&line, &MAXLEN, stdin)) > 0)
    {

        if (nlines >= MAXLINES)
            return -1;

        else
        {
            *(line + len - 1) = '\0';
            char *line2 = malloc(len + 1);
            strcpy(line2, line);
            *lineptr++ = line2;
            nlines++;
        }
    }

    return nlines;
}

/* writelines: write output lines */
void writelines(char **lineptr, int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

int main()
{
    int nlines;
    char **lineptr = malloc(MAXLINES);

    /* number of input lines read */
    if ((nlines = readlines(lineptr)) >= 0)
    {
        writelines(lineptr, nlines);
        return 0;
    }

    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}
