/*Exercise 2-2. Write a loop equivalent to the for loop above without using && or || .
    for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
*/

#include <stdio.h>

int main(){
    int i, c;
    const int lim=80;
    char s[lim];

     for (i=0;  i< lim-1 ? (c=getchar()) != '\n' ? c != EOF : 0 : 0; ++i)
        s[i] = c;

    s[i] = '\0';
    
}