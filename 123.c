// Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
// handle quoted strings and character constants properly. C comments don't nest.
#include <stdio.h>
#define OUT 0
#define INLINE 1
#define BLOCK 2
#define NONE '\0'

int main(){
    char previous;
    int c, status;
    status = OUT;

    previous = NONE;
    while ((c= getchar()) != EOF){

        if(previous == '/'){

            if (c == '/'){
                status = INLINE;  
            } 
            else if (c=='*'){
                status  = BLOCK;
            }
            else{
                putchar(previous);
                putchar(c);
            }
            previous = NONE;
        }

        else if (previous == '*'){
            
            if (c == '/'){
                status = OUT;
                previous = NONE;
            }
        }

        else if (status == OUT ){
            
            if (c == '/'){
                previous = '/';
            }
            else{
                putchar(c);
            }
        }
        
        else if (status == INLINE){
            
            if (c == '\n'){
                status = OUT;
                putchar(c);
            }
        }

        else if (status == BLOCK){
            
            if (c == '*'){
                previous = '*';
            }
        }
    }
}
