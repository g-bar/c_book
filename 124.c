#include <stdio.h>
#define MAXLEN 10000 

/*  
    Check for whitespace inside double or single quotes. (unmatched quotes)
    
    Check for valid escape sequences.
    
    Remove all valid strings
    Remove valid comments.
    Check unmatched block comment

    Check unmatched parentheses, brackets and braces.
    
*/

int opposite(int c);
void char_expected_error(int c);

int main(){
    int stack[MAXLEN];
    int c,i,o;
    i = o = 0;
    
    while ( (c= getchar())!= EOF){
        if (c == '(' || c == '{' || c == '['){
            stack[i++] = c;
        }

        else if ( c== ')' || c=='}' || c==']'){
            if ((o = opposite(stack[--i])) != c){
                char_expected_error(o);
                return 0;
            }
        }
    }

    if (i != 0){
        char_expected_error(opposite(stack[--i]));
    }
}

int opposite(int c){
    switch (c){
        case ')':
            return '(';
        case '(':
            return ')';
        case '}':
            return '{';
        case '{':
            return '}';
        case ']':
            return '[';
        case '[':
            return ']';
        default: 
            return 0;
    }
}


void char_expected_error(int c){
    printf("Syntax Error: '%c' Expected\n", c);
}