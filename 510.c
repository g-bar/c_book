#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    long double *buffer = malloc(100);
    long double number;

    int len;
    char val;
    long double a, b;

    while (*(++argv))
    {
        char *endptr;
        len = strlen(*argv);
        number = strtold(*argv, &endptr);
        val = **argv;

        if ((len > 1 && *endptr && (val != '+' || val != '-' || val != '*' || val != '/')))
        {
            printf("Invalid argument %s\n", *argv);
            return 1;
        }

        if (!*endptr)
        {
            *buffer++ = number;
        }

        else if (*endptr)
        {
            a = *(--buffer);
            b = *(--buffer);

            if (*endptr == '+')
                *buffer = a + b;
            else if (*endptr == '-')
                *buffer = b - a;
            else if (*endptr == '*')
                *buffer = a * b;
            else
                *buffer = b / a;

            buffer++;
        }
    }
    printf("%Lf\n", *(buffer - 1));
}
