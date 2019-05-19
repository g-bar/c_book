/* Write a recursive version of the function reverse(s) , which reverses the
string s in place. */

void reverse(char s[])
{
    static int i, j;
    
    if (s[i]){
        int c = s[i++];
        reverse(s);
        s[j++] = c;
    }

    if (i==j){
        i=0, j=0;
    }
}
