// Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
// number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab .
// When either a tab or a single blank would suffice to reach a tab stop, which should be given
// preference?

#include <stdio.h>

#define N 4

int main(){
    int c,i;
    int blanks = 0;
    int tabs, rem;

    while ((c = getchar()) != EOF){
        if (c == ' '){
            ++blanks;
            continue;
        }
        else{
            tabs = blanks / N;
            rem = blanks % N;
            for (i=0;i<tabs;i++){
                putchar('\t');
            }
            for (i=0; i<rem; i++){
                putchar(' ');
            }
            blanks = 0;
            putchar(c);
        }
    }
}
