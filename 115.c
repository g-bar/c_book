#include <stdio.h>
#define MAXLINE 10 /* maximum input line length */
int getline(char line[], int maxline);
void copy(char to[], char from[]);
/* print the longest input line */
main(){
    int len; /* current line length */
    int max; /* maximum length seen so far */
    int save_len;
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = save_len = 0;
    
    while ((len = getline(line, MAXLINE)) > 0){
        
        save_len += len;
        
        if (len == MAXLINE - 1){
            copy(longest, line);
            continue;
        }
        
        else{
            len = save_len;
            save_len = 0;
        }

        if (len > max) {
            max = len;
            if (len <MAXLINE -1){
                copy(longest,line);
            }
        }
    }
    
    if (max > 0) /* there was a line */
        printf("%s\n%d", longest, max);
        
    return 0;
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}