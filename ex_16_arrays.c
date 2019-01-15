#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define OFFSET 48
#define TRUE 1
#define FALSE 0

int main(){
    int *ndigits;
    int i;
    int c;
    int nblanks;
    int nchars;
    int digit;

    ndigits = (int *) calloc(SIZE,sizeof(int));

    nblanks = nchars = 0;
    
    while ((c = getchar()) != EOF){
        digit = FALSE;
        for (i=0;i<SIZE;i++){
            if (i+OFFSET == c){
                ndigits[i]++;
                digit = TRUE;
                break;
            }
        }

        if (digit) continue;

        if (' ' == c || '\t' == c || '\n'==c){
            nblanks++;
        }
        
        else{
            nchars++;
        }
    }

    for (i=0; i<SIZE;i++){
        printf("%d: %d\n", i, ndigits[i]);
    }
    printf("blanks: %d\n", nblanks);
    printf("other: %d\n", nchars);
}
