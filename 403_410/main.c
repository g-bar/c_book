#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h>
#include <constants.h>

int getop(char []);
void push(double);
double pop(void);
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
            case '\n':
                printf("\t%.8g\n", pop());
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
    if (!strcmp(s, SHOW)){
        show(pop());
    }else if (!strcmp(s, SWAP)){
        swap();
    }else if (!strcmp(s, DUP)){
        dup();
    }else if (!strcmp(s, CLEAR)){
        clear();
    }else{
        printf("error: unknowh command %s\n", s);
    }
}