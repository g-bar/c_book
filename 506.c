/*Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. Good possibilities include getline (Chapters 1 and 4),
atoi, itoa, and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop (Chapter 4)
*/

#include <stdio.h>

int getline_(char *s, int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
    {
        *(s + i) = c;
        if (c == '\n')
            break;
    }
}

int atoi(char *s)
{
    int n;
    for (n = 0; *s >= '0' && *s <= '9'; s++)
        n = 10 * n + (*s - '0');
    return n;
}

static char *t; // Keep pointer across calls
static int calls = 0;

void itoa_(int n)
{
    calls++;

    if (n < 0)
    {
        *t++ = '-';
        n = -n;
    }

    if (n / 10)
        itoa_(n / 10);

    *t++ = n % 10 + '0';
    calls--;

    if (calls == 0)
        *t = '\0';
}

void itoa(int n, char *s)
{
    t = s;
    itoa_(n);
}

static char *u;
static int i = 0;

void reverse_()
{

    if (*(u + i))
    {
        char c = *(u + i++);
        reverse_();
        *u++ = c;
        return;
    }

    *u = '\0';
    i = 0;
}

void reverse(char *s)
{
    u = s;
    reverse_();
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t)
{

    char *u;
    char *v;
    char *w;

    u = v = s;

    if (*s == '\0' || *t == '\0')
        return -1;

    for (; *u != '\0'; u++)
    {

        v = u;
        w = t;

        while (*w != '\0' && *v == *w)
            v++, w++;

        if (*w == '\0')
            return u - s;
    }

    return -1;
}
