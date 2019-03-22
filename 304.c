/* Exercise 3-4. In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2 ^ wordsize-1 ). Explain why
not. Modify it to print that value correctly, regardless of the machine on which it runs. */

/* Original K&R function */

/* itoa: convert n to characters in s 
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) //record sign 
        n = -n; // make n positive 
    i = 0;
    do { // generate digits in reverse order 
        s[i++] = n % 10 + '0'; // get next digit 
    } while ((n /= 10) > 0); // delete it 
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
*/

/*
Explanation: The error occurs when making n positive.
In a two's complement system the negative of a number is 
represented by taking the one's complement (e.g inverting all bits)
and the adding 1. For the largest negative number this originates an overflow, getting
back the original number.

For example for a 3-bit signed int representation.

Largest negative value: -4  (100)
One's complement :           (011)
Adding one:                   (100)  We end up at the original number

In turn this causes the while conditional (n/= 10 > 0) to fail in the first step.
See below for a proposed solution that handles this case.

*/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#define MAXLEN 12

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

//itoa: convert n to characters in s 
void itoa(int n, char s[])
{
    int i, sign;
    
    sign = n<0 ? -1 : 1;
    i = 0;

    do {  // generate digits in reverse order 
        s[i++] = sign * (n % 10) + '0'; // get next digit 
    } while ((n /= 10) != 0); // delete it
    if (sign == -1)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


int main()
{   char s[MAXLEN];
    
    itoa(INT_MIN, s);   
    printf("%s\n", s);
    itoa(0,s);
    printf("%s\n", s);
    itoa(INT_MAX,s);
    printf("%s\n", s);
}