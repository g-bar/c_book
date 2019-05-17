/* Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a
a string by calling a recursive routine. */
#define MAXLEN 100

char * itoa(int n)
{
    static char s[MAXLEN];
    static int i;

    if (n<0){
        s[i++] = '-';
        n = -n;
    }

    if (n/10){
        itoa(n/10);
    }

    s[i++] = n%10 + '0';
    s[i] = '\0';
    return s;
}
