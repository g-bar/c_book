// Exercise 2-5. Write the function any(s1,s2) , which returns the first location in a string s1
// where any character from the string s2 occurs, or -1 if s1 contains no characters from s2 .
// (The standard library function strpbrk does the same job but returns a pointer to the
// location.)

#include <stdio.h>

int any(char s1[], char s2[])
{
    int i, j, c;
    for (i=0, c='\0'; s1[i] != '\0' && c == '\0' ; i++) {
        for (j = 0; s1[i] != (c = s2[j]) && c != '\0'; j++)
            ;
    }
    
    return c == '\0' ? -1 : i-1;
}


int main (int argc, char  *argv[])
{
    printf("%d", any(argv[1], argv[2]));
}
