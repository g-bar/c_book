#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINES 100000   /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort_(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines;
    /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort_(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}
size_t MAXLEN = 1000;

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, *line;
    nlines = 0;
    line = malloc(MAXLEN);
    while ((len = getline(&line, &MAXLEN, stdin)) > 0)
    {

        if (nlines >= maxlines || (p = malloc(len)) == NULL)
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

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* qsort_: sort v[left]...v[right] into increasing order */
void qsort_(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort_(v, left, last - 1);
    qsort_(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
