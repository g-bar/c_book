#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort_(void *v[], int left, int right, int (*comp)(const void *, const void *));
void swap(void *v[], int i, int j);
int numcmp(const char *s1, const char *s2);

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