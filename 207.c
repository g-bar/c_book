// Write a function invert(x,p,n) that returns x with the n bits that begin at
// position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.

#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, int p, int n)
{   
    unsigned mask = ~(~0<<n)<<p+1-n;
    return x & ~mask | ~x & mask ;
}


int main(int argc, char * argv[])
{
    unsigned args[3];
    int i;
    char ** end;
    for (i = 1;i<=3;i++){
        args[i-1] = strtoul(argv[i], end,10 );
    }
    
    printf("%u", invert(args[0],args[1],args[2]));
}