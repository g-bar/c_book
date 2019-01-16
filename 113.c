#include <stdio.h>
#include <stdlib.h>
#define MAX_WORD_LENGTH 100

int main(){
    int *length;
    int count;
    int c;
    int i,j;

    length = (int *) calloc(MAX_WORD_LENGTH,sizeof(int));

    count = 0;
    
    
    while ((c = getchar()) != EOF){
        if ('\n' == c || '\t' == c || ' ' == c){
            ++length[count];
            count = 0;
            
        }
        else {
            ++count;
        }
    }

    for (i=1; i<MAX_WORD_LENGTH;i++){
        if (!(count = length[i])) continue;
        printf("%3d: ", i);
        
        for(j=0;j<count;j++){
            printf("█");
        }
        printf("\n\n");
    }
        
}
