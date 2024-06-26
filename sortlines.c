#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLINES 5000    /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines, int fields);
void writelines(char *lineptr[], int nlines, int reversed);
void qsort_(void *v[], int left, int right, int (*comp)(const void *, const void *));
void swap(void *v[], int i, int j);
int numcmp(const char *, const char *);
int strcmp_(const char *s1, const char *s2);
int strcmpf(const char *s1, const char *s2);
int strcmpd(const char *s, const char *t);
int strcmpfd(const char *s1, const char *s2);
int fieldcmp(const char *s1, const char *s2);
static int **options;
static char ***keys;

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int fold = 0;
    int dir = 0;
    int field = 0;
    int fields = 0;
    char c;
    int i, j, k;
    int nchars;
    int (*cmpfun)(const void *, const void *) = (int (*)(const void *, const void *))strcmp_;
    options = calloc(argc - 1, sizeof(*options));
    int atfield;

    for (i = 0; i < argc - 1; i++)
    {
        *(options + i) = calloc(5, sizeof(int));
    }

    for (i = 0; i < argc - 1 && **++argv == '-'; i++)
    {
        while ((c = *++*argv))
        {
            if (field)
            {
                if (c == 'n')
                    options[i][1] = 1;
                else if (c == 'r')
                    options[i][2] = 1;
                else if (c == 'f')
                    options[i][3] = 1;
                else if (c == 'd')
                    options[i][4] = 1;

                if (isdigit(c) && options[i][0] == 0)
                {
                    options[i][0] = atoi(*argv);
                }
            }

            else
            {

                if (c == 'n')
                    numeric = 1;
                if (c == 'r')
                    reverse = 1;
                if (c == 'f')
                    fold = 1;
                if (c == 'd')
                    dir = 1;
                if (c == 'k')
                    field = 1;
            }
        }
        if (field)
        {
            fields = 1;
            i++;
        }
        field = 0;
    }

    /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES, fields)) >= 0)
    {

        if (fields)
        {
            keys = calloc(nlines, sizeof(*keys));
            for (i = 0; i < nlines; i++)
            {
                keys[i] = calloc(argc - 1, sizeof(**keys));
                nchars = strlen(lineptr[i]);
                atfield = 0;

                for (j = 0, k = 0; j < nchars && k < argc - 1; j++)
                {
                    if (!isblank(c = lineptr[i][j]) && !atfield)
                    {
                        keys[i][k] = lineptr[i] + j;
                        atfield = 1;
                        k++;
                    }

                    if (isblank(c) && atfield)
                    {
                        atfield = 0;
                    }
                }
            }
        }

        if (fields)
        {
            cmpfun = (int (*)(const void *, const void *))fieldcmp;
        }

        else if (numeric)
            cmpfun = (int (*)(const void *, const void *))numcmp;
        else
        {
            if (fold && dir)
                cmpfun = (int (*)(const void *, const void *))strcmpfd;
            else if (fold)
                cmpfun = (int (*)(const void *, const void *))strcmpf;
            else if (dir)
                cmpfun = (int (*)(const void *, const void *))strcmpd;
        }

        qsort_((void **)lineptr, 0, nlines - 1, cmpfun);
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
int readlines(char *lineptr[], int maxlines, int fields)
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

int fieldcmp(const char *s1, const char *s2)
{
    int field = options[0][0];

    int fields = 1;

    while ((fields < field) && &s1)
    {
        while (isblank(&s1))
            s1++;
        while (!isblank(&s1))
            s1++;
        fields++;
    }

    return 0;
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

int i(char c)
{
    return c;
}

int lower(char c)
{
    if (c >= 65 && c <= 90)
        return c + 32;

    return c;
}

int dirc(char c)
{
    if (isalnum(c) || isblank(c))
        return c;
    return ' ';
}

int dircf(char c)
{
    return dirc(lower(c));
}

int _strcmp(const char *s, const char *t, int (*transform)(char))
{
    int i;
    int a, b;

    for (i = 0; (a = (*transform)(s[i])) == (b = (*transform)(t[i])); i++)
        if (s[i] == '\0')
            return 0;
    return a - b;
}

int strcmp_(const char *s, const char *t)
{
    return _strcmp(s, t, i);
}

int strcmpf(const char *s, const char *t)
{
    return _strcmp(s, t, lower);
}

int strcmpd(const char *s, const char *t)
{
    return _strcmp(s, t, dirc);
}

int strcmpfd(const char *s, const char *t)
{
    return _strcmp(s, t, dircf);
}
