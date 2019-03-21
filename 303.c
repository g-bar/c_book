/* Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2 . Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z . Arrange
that a leading or trailing - is taken literally. */

void expand(char s1[], char s2[])
{
    int i, j;
    char first, last;
    i = j = 0;
    
    //Check for leading '-'
    if (s2[j] == '-'){
        s1[i] = s2[j];
        i++, j++;
    }
    
    for ( ; s2[j] != '\0' ; j++){
        for (first = s2[j] ; s2[j+1] == '-' && s2[j+2] != '\0' ; j+=2)
            ;
        
        for (last = s2[j]; first<=last; first++){
            s1[i++] = first;
        }
        
    }
    s1[i] = '\0';
}
