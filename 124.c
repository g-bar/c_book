#include <stdio.h>
#define MAXLEN 10000 
#define STANDARD 0
#define STRING 1
#define COMMENT 2
#define ESCAPE 3

/*  
    Check for whitespace inside double or single quotes. (unmatched quotes)
    
    Check for valid escape sequences.
    
    Remove all valid strings
    Remove valid comments.
    Check unmatched block comment

    Check unmatched parentheses, brackets and braces.
    
*/

int opposite(int c);
int char_expected_error(int c);
int raise_error(char *message);
int check_valid_escape_character(int c);

int main(){
    int stack[MAXLEN];
    int c,i,o, mode, opening_quote;
    i = o = 0;
    mode = STANDARD;
    
    while ( (c= getchar())!= EOF){
        if (mode == STRING){
            opening_quote = stack[i];
            if (c == '\\'){
                mode = ESCAPE;
            }
            
            else if (c == '\n'){
                return raise_error("Missing closing quote\n");
            }
            
            else if (c == opening_quote){
                mode = STANDARD;
            }
        }

        else if (mode == ESCAPE){
            if (! check_valid_escape_character(c)){
                return invalid_escape_sequence_error(c);
            }
            mode = STRING;
        }
        
        else if (c == '\'' || c == '"'){
            mode = STRING;
            stack[i] = c;
        }

        else if (c == '(' || c == '{' || c == '['){
            stack[i++] = c;
        }

        else if ( c== ')' || c=='}' || c==']'){
            if ((o = opposite(stack[--i])) != c){
                return char_expected_error(o);
                
            }
        }
    }

    if (mode == STRING){
        return raise_error("Missing closing quote\n");
    }
    else if (i != 0){
        return char_expected_error(opposite(stack[--i]));
    }
    return 0;
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
            return 1;
    }
}


int char_expected_error(int c){
    printf("Syntax Error: '%c' Expected\n", c);
    return 1;
}

int invalid_escape_sequence_error(int c){
    printf("Invalid escape sequence \\%c\n", c);
    return 1;
}

int raise_error(char *message){
    printf(message);
    return 1;
}

int check_valid_escape_character(int c){
    char *characters = "abefnrtv\\\'\"\?";
    int i;
    for (i=0;i<12;i++){
        if (c == characters[i]){
            return 1;
        }
    }
    return 0;
}