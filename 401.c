// Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
// occurrence of t in s , or -1 if there is none.
#include <string.h>
#include <stdio.h>

int strindexf(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int strindex(char s[], char t[])
{
    int len, i;
    char * sp;
    
    for (sp = s, len = strlen(t); (i = strindexf(sp, t)) >= 0; sp+=i+len)
        ;
    
    return  sp - s > 0 ? sp - s - len : -1;
}
