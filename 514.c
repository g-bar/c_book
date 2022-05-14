
#include <stdio.h>
#include <string.h>
#define MAXLINES 5000    /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reversed);
void qsort_(void *v[], int left, int right, int (*comp)(const void *, const void *));
int numcmp(const char *, const char *);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int c = 0;
    int i = 0;

    while (--argc >= 1 && **++argv == '-')

        while (c = *++*argv)
        {
            if (c == 'n')
                numeric = 1;
            if (c == 'r')
                reverse = 1;
        }

    /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort_((void **)lineptr, 0, nlines - 1, (int (*)(const void *, const void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines, reverse);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}