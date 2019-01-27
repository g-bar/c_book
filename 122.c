// Write a program to ``fold'' long input lines into two or more shorter lines after
// the last non-blank character that occurs before the n -th column of input. Make sure your
// program does something intelligent with very long lines, and if there are no blanks or tabs
// before the specified column.

#include <stdio.h>
#include <string.h>
#define N 10
#define TRUE 1
#define FALSE 0


int getline(char s[], int lim);
int find_last_non_blank(char s[], int len);

int main(){
    int len,i, last_non_blank;
    int c;
    char line[N];
    int limit;
    limit = N ;
    
    while ( (len = getline(line, limit)) > 0){
        limit = N;
        if (line[len-1] == '\n'){
            printf("%s", line);
        }
        else if ((last_non_blank = find_last_non_blank(line, len)) >= 0){
            fold_line(line, last_non_blank, len);
            limit  = (N - len) + last_non_blank + 2;
        } 
        else{
            printf("%s\n",line);
        }
    }
    
}

int fold_line(char line[], int last_non_blank, int len){
    int c,i;
    for (c=line[i=0]; i<=last_non_blank; c=line[++i]){
        putchar(c);
    }
    putchar('\n');
    for (c=line[++i]; i<len; c=line[++i]){
        putchar(c);
    }
}

int find_last_non_blank(char s[], int len){
    int blank = FALSE;
    int i, c;
    
    for (i=len-1; i>=0; --i){
        c = s[i];
        
        if (blank && (c != ' ' && c != '\t' && c != '\n'))
            return i;
        else if (c == ' ' || c == '\t' || c == '\n'){
            blank = TRUE;
        }
    }
    return -1;
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