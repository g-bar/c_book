#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <constants.h>

int getop(char []);
void push(double);
double pop(void);
void pushvar(int);
void savevar(double);
void show(int);
void dup(void);
void swap(void);
void clear(void);
void execute(char []); /*Execute a command*/

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        if (islower(type) || type == '_'){
            pushvar(type);
            continue;
        }
        
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case COMMAND:
                execute(s);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2= pop();
                if (op2 != 0.0)
                    push((double)((int) pop() % (int) op2));
                else
                    printf("error zero divisor\n");
                break;
            case '~':
                push(-pop());
                break;
            case '=':
                pop();
                savevar(pop());
                break;
            case '\n':
                pushvar('_');
                pop();
                savevar(op2 = pop());
                printf("\t%.8g\n", op2);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

void execute(char s[])
{
    if (!strcmp(s, "show")){
        show(pop());
    }else if (!strcmp(s, "swap")){
        swap();
    }else if (!strcmp(s, "dup")){
        dup();
    }else if (!strcmp(s, "clear")){
        clear();
    } else if (!strcmp(s, "sin")){
        push(sin(pop()));
    } else if (!strcmp(s, "exp")){
        push(exp(pop()));
    }else if (!strcmp(s, "pow")){
        int exp = pop();
        push( pow(pop(), exp));
    } else{
        printf("error: unknown command %s\n", s);
    }
}