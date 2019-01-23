// Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
// Should n be a variable or a symbolic parameter?

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
