#include <stdio.h>
#define FALSE 0
#define TRUE 1

int main(){
    int c = 0;
    int flag = FALSE;
    while( (c = getchar()) != EOF){        
        if (c== ' ' || c == '\n' || c == '\t'){
            if (flag) putchar('\n');
            flag = FALSE;
        }
        
        else{
            putchar(c);
            flag = TRUE;
        }

    }
}