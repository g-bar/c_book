/* Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a
a string by calling a recursive routine. */

void itoa(int n, char s[])
{
    static int i, calls;
    calls++;
    
    if (n<0){
        s[i++] = '-';
        n = -n;
    }
    if (n/10){
        itoa(n/10, s);
    }
    
    s[i++] = n%10 + '0';
    calls--;
    
    if (calls==0){
        s[i] = '\0';
        i=0;
    }
}
