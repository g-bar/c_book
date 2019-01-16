#include <stdio.h>
#include <stdlib.h>

int main(){
    int c, i,j;
    int *count;
    count = calloc(126-9, sizeof(int));
    while ((c=getchar())!=EOF){
        if ('\t'<= c && c<='~')
            ++count[c-'\t'];
    }

    for (i=0;i<126-9;i++){
        if ((c = count[i]) != 0){
            printf("%c: ", i+'\t');
            for (j=0;j<c;j++){
                printf("|");
            }
            printf("\n\n");
        }
        
    }
}
