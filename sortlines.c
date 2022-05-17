#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLINES 5000    /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines, int fold, int dir);
void writelines(char *lineptr[], int nlines, int reversed);
void qsort_(void *v[], int left, int right, int (*comp)(const void *, const void *));
void swap(void *v[], int i, int j);
int numcmp(const char *, const char *);
int strcmp_(const char *s1, const char *s2);
void foldchars(char *line);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int fold = 0;
    int dir = 0;
    int c = 0;
    int i = 0;

    while (--argc >= 1 && **++argv == '-')

        while (c = *++*argv)
        {
            if (c == 'n')
                numeric = 1;
            if (c == 'r')
                reverse = 1;
            if (c == 'f')
                fold = 1;
            if (c == 'd')
                dir = 1;
        }

    /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES, fold, dir)) >= 0)
    {
        qsort_((void **)lineptr, 0, nlines - 1, (int (*)(const void *, const void *))(numeric ? numcmp : strcmp_));
        writelines(lineptr, nlines, reverse);
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
int readlines(char *lineptr[], int maxlines, int fold, int dir)
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

            if (fold)
                foldchars(p);

            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int reversed)
{
    if (reversed)
        lineptr = lineptr + nlines;

    while (nlines-- > 0)
        if (reversed)
            printf("%s\n", *--lineptr);
        else
            printf("%s\n", *lineptr++);
}

/* qsort_: sort v[left]...v[right] into increasing order */
void qsort_(void *v[], int left, int right, int (*comp)(const void *, const void *))
{
    int i, last;
    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort_(v, left, last - 1, comp);
    qsort_(v, last + 1, right, comp);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void foldchars(char *line)

{
    int n = strlen(line);

    int offset = 0;

    while (n-- > 0)
    {
        offset = (*line >= 65 && *line <= 90) ? 32 : 0;
        *line++ += offset;
    }
}

int numcmp(const char *s1, const char *s2)

{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int strcmp_(const char *s, const char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}
