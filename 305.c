/* Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s . In particular, itob(n,s,16) formats s as a
hexadecimal integer in s . */

#include <stdio.h>
#include <string.h>

void reverse(char s[]);

void itob(int n, char s[], int b)
{
    int i, sign;
    int digit;
    sign = n<0 ? -1 : 1;
    i = 0;

    do {  // generate digits in reverse order 
        digit = sign * n%b;
        s[i++] =  digit + (digit < 10 ? '0' : 'A' - 10); // get next digit 
    } while ((n /= b) != 0); // delete it
    if (sign == -1)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}