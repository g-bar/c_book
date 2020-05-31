// Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
// Should n be a variable or a symbolic parameter?

#include <stdio.h>

#define N 4

int main()
{
    char c;
    int column = 0;

    while ((c = getchar()) != EOF)
    {
        column++;
        if (c == '\t')
        {
            putchar(' ');
            while ((++column - 1) % N != 0)
            {
                putchar(' ');
            }
            column--;
        }
        else
        {
            putchar(c);
            if (c == '\n')
                column = 0;
        }
    }
}
