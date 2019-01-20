// Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
// and to delete entirely blank lines.

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getline(char line[], int maxline);
int is_blank(char c);

main(){
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    char secondline[MAXLINE];
    int i;
    int last_non_blank;
    while ((len = getline(line, MAXLINE)) > 0){
        for (i=len-1; is_blank(line[i]); i--){
            ; //pass
        }
        last_non_blank = i;
        for (i=0; i<= last_non_blank;i++){
            putchar(line[i]);
        }
        if (last_non_blank > 0){
            putchar('\n');
        }
    }
    return 0;
}

int is_blank(char c){
    return (c == ' ' || c== '\t' || c=='\n');
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
