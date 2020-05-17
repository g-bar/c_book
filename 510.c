#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
    long double *buffer = malloc(100);
    long double number;
    char *endptr;
    int len;
    char val;
    long double a, b;

    while (*(++argv))
    {
        len = strlen(*argv);
        number = strtold(*argv, &endptr);
        val = **argv;

        if (!endptr && (len > 1 && *endptr || val != '+' || val != '-' || val != '*' || val != '/'))
        {
            printf("Invalid argument %s\n", *argv);
            return 1;
        }

        if (!endptr)
        {
            *buffer++ = number;
        }
        else if (endptr)
        {
            a = *(buffer - 2);
            b = *(buffer - 1);

            if (*endptr == '+')
                *(buffer - 2) = a + b;
            else if (*endptr == '-')
                *(buffer - 2) = a - b;
            else if (*endptr == '*')
                *(buffer - 2) = a * b;
            else
                *(buffer - 2) = a / b;

            buffer -= 2;
        }
    }
    printf("%Lf\n", *buffer);
}