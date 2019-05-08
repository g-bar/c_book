#include <stdio.h>
#include <constants.h>

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
int vars[27];
int lastvar;

int max(int,int);

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void pushvar(int var)
{
    if (var == '_')
        var = 26 + 97;
    push(vars[var-97]);
    lastvar = var;
}

void savevar(double val)
{
    vars[lastvar-97] = val;
}

void show(int n)
{
    int i;
    for (i= max(sp-n, 0) ; i<sp ; i++){
        printf("%f ", val[i]);
    }
    
}

void dup(void)
{   int i;

    if (sp > 50){
        printf("error: not enough space on stack");
    }
    else{

        for (i=0; i<sp; i++){
            val[sp+i] = val[i];
        }
        sp = sp + i;
    }
}

void swap(void)
{
    double a, b;
    if (sp >= 2){
        a = pop();
        b = pop();
        push(a);
        push(b);

    } else{
        printf("error: can't swap, less than 2 elements on stack\n");
    }
}

void clear(void)
{
    sp = 0;
}

int max(int a, int b)
{
    if (a >= b){
        return a;
    }
    return b;
}