// Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
// Should n be a variable or a symbolic parameter?

#include <stdio.h>

#define N 4

int main(){
    int c,i;
    char tab[N];
    for (i=0;i<N;i++){
        tab[i] = ' ';
    }


    while ((c = getchar()) != EOF){
        if (c == '\t'){
            printf("%s",tab);
        }
        else{
            putchar(c);
        }

    }
}