// Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
// unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
// double, escape sequences, and comments. (This program is hard if you do it in full
// generality.)

#include <stdio.h>
#define MAXLEN 10000 
#define STANDARD 0
#define STRING 1
#define INLINE 2
#define BLOCK 3
#define ESCAPE 4

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
        // String mode
        if (mode == STRING){
            //Save the opening quote ' or "
            opening_quote = stack[i];
            if (c == '\\'){
                mode = ESCAPE;
            }
            
            //If a line break breaks the string raise an error
            else if (c == '\n'){
                return raise_error("Missing closing quote\n");
            }
            
            // Find the closing quote and go back to standard mode
            else if (c == opening_quote){
                mode = STANDARD;
            }
        }

        //If a escape character \ was found check if it's a valid sequence
        //If it's valid go back to string mode
        else if (mode == ESCAPE){
            if (! check_valid_escape_character(c)){
                return invalid_escape_sequence_error(c);
            }
            mode = STRING;
        }

        //If in an inline comment do nothing until we find a line break
        else if (mode == INLINE){
            if (c == '\n'){
                mode = STANDARD;
            }            
        }

        // In a block comment
        else if (mode == BLOCK){
            // Look for a * to indicate a comment closing sequence
            if (c == '*'){
                stack[i] = c;
            }

            //If previous character is *
            else if (stack[i] == '*'){
                // Found closing comment sequence */, go back to standard mode
                if ( c == '/'){
                    mode = STANDARD;
                }

                // Remain in block mode                                                
                else{
                    stack[i] = 0;
                }
            }
            
        }
        
        //If we find an opening bracket push it to the stack
        else if (c == '(' || c == '{' || c == '['){
            stack[i++] = c;
        }

        //If we find a closing bracket check that the previous bracket matches, clean it from the stack
        //If bracket doesn't match raise an error
        else if ( c== ')' || c=='}' || c==']'){
            if ((o = opposite(stack[--i])) != c){
                return char_expected_error(o);
                
            }
        }
        
        //If we find an opening quote go into string mode, save the opening quote mark (' or ")
        else if (c == '\'' || c == '"'){
            mode = STRING;
            stack[i] = c;
        }

        // If a / is in the stack 
        else if (stack[i] == '/'){
            // A second / is found we are in an inline comment
            if (c == '/'){
                mode = INLINE;  
            } 

            // A * is found, it's a block comment
            else if (c=='*'){
                mode  = BLOCK;
            }

            // No comment
            else {
                stack[i] = 0;
            }
        }
        
        // If we find a / save it, it might be the beginning of a comment
        else if (c == '/'){
            stack[i] = c;
        }
    }

    // If we reach EOF and still in string mode raise an error
    if (mode == STRING){
        return raise_error("Missing closing quote\n");
    }

    // If we reach EOF and still in a block comment raise an error
    else if (mode == BLOCK){
        return raise_error("Comment unclosed at end of file\n");
    }

    // If the stack is not empty, there's at least one unmatch bracket
    else if (i != 0){
        return char_expected_error(opposite(stack[--i]));
    }

    // No errors
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
