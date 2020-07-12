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

int badUsage()
{
    printf("Usage tail -n input \n");
    return 1;
    ;
}



int main(int argc, char *argv[])
{
    long int n;
    char *endptr, *str;
    char *input = argv[1];

    // Parse input and check for errors

    if (argc < 2)
        return badUsage();

    if (argc == 3)
    {
        errno = 0;
        if (argv[1][0] != '-')
            return badUsage();
        n = strtol(++(argv[1]), &endptr, 10);
        if (errno == ERANGE)
            return badUsage();
        input = argv[2];
    }

    n = n || 10;

    return 0;
}
