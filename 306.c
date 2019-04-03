#include <stdio.h>
#include <stdlib.h>
#include <reverse.h>
#define MAXLEN 100
/* Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough. */

void pad(char s[], int length, int minwidth)
{
    int i;
    for (i = length; i< minwidth ; i++){
        s[i] = '0';
    }
    s[i] = '\0';
}

//itoa: convert n to characters in s 
void itoa(int n, char s[], int minwidth)
{
    int i, sign, zeroes;
    
    sign = n<0 ? -1 : 1;
    i = 0;

    do {  // generate digits in reverse order 
        s[i++] = sign * (n % 10) + '0'; // get next digit 
    } while ((n /= 10) != 0); // delete it
    if (sign == -1)
        s[i++] = '-';
    pad(s, i, minwidth);
    reverse(s);
}

int main (int argc, char ** argv)
{
    int i, minwidth;
    char s[MAXLEN];
    
    i = 801234;
    minwidth = 100;
    itoa(i, s, minwidth);
    printf("%s\n", s);
}
