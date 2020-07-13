/* Write the program tail , which prints the last n lines of its input. By default, n
is set to 10, let us say, but it can be changed by an optional argument so that
tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the
input or the value of n. Write the program so it makes the best use of available storage; lines
should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
fixed size. */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

size_t MAXLINES = 1000;
size_t MAXLEN = 1000;
int readlines(char *[]);
int badUsage();

int main(int argc, char *argv[])
{
    long int n;
    int nlines;
    int currentline;
    char *endptr, *str;
    char *lineptr = malloc(MAXLINES);

    // Parse input and check for errors

    if (argc == 2)
    {
        errno = 0;
        if (argv[1][0] != '-')
            return badUsage();
        n = strtol(++(argv[1]), &endptr, 10);
        if (errno == ERANGE)
            return badUsage();
    }

    n = n || 10;

    nlines = readlines(lineptr);

    while ((++currentline) > nlines - n && currentline < nlines)
        printf("%s\n", lineptr++);

    return 0;
}

/* readlines: read input lines */
int readlines(char *lineptr[])
{
    int len, nlines;
    char *p, *line;
    nlines = 0;
    line = malloc(MAXLEN);
    while ((len = getline(&line, &MAXLEN, stdin)) > 0)
    {

        if (nlines >= MAXLINES || (p = malloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

int badUsage()
{
    printf("Usage tail -n input \n");
    return 1;
}
