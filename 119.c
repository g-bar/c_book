// Exercise 1-19. Write a function reverse(s) that reverses the character string s . Use it to
// write a program that reverses its input a line at a time.

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getline(char line[], int maxline);
void reverse(char s[]);
void copy(char to[], char from []);

main(){
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    
    while ((len = getline(line, MAXLINE)) > 0){
        reverse(line);
        printf("%s", line);
    }
    return 0;
}


void reverse(char s[]){
    int len = str_len(s);
    char temp[len+1];
    int i;
    copy(temp, s);
    
    i=0;
    while (s[i] != '\0'){
        s[i] = temp[len-1-i];
        ++i;
    }
}

/* getline: read a line into s, return length */
int getline(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
        }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

int str_len(char str[]){
    int i;
    for (i=0; str[i]!='\0'; i++){
        ; //pass
    }
    return i;
}