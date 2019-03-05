// Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
// position p set to the rightmost n bits of y , leaving the other bits unchanged.

#include <stdio.h>
#include <stdlib.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned mask = ~(~0<<n)<<(p+1-n);
    return x &~mask | y&mask;
}

int main(int argc, char * argv[])
{
    unsigned args[4];
    int i;
    char *end;
    for (i = 1;i<=4;i++){
        args[i-1] = strtoul(argv[i], &end,10 );
    }
    
    printf("%u", setbits(args[0],args[1],args[2],args[3]));
}
