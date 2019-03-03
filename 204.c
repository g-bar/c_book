// Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
// s1 that matches any character in the string s2 .

#include <stdio.h>

int any(char s[], int c){
    int i, sc;
    for (i=0 ; (sc = s[i]) != '\0' && sc != c; i++)
        ; // empty for block
    // If the for didn't reach the end of the string, at least one character in s matches c
    return sc != '\0';
}

void squeeze(char s1[], char s2[])
{
    int i, j, c;
    for (i = j = 0; (c=s1[i]) != '\0'; i++){
        if (!any(s2, c)){
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int main(int argc, char *argv[]){
    squeeze(argv[1], argv[2]);
    printf("%s", argv[1]);

}