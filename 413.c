#include <string.h>

void reverse(char s[])
{
    static int i, j;
    if (j==0){
        j = strlen(s) -1 ;
    }

    if (i<j){
        char c = s[j];
        s[j--] = s[i];
        s[i++] = c;        
        reverse(s);
    }

    i=0;
    j=0;

}
