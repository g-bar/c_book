// Exercise 2-3. Write a function htoi(s) , which converts a string of hexadecimal digits
// (including an optional 0x or 0X ) into its equivalent integer value. The allowable digits are 0
// through 9 , a through f , and A through F.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int htoi(char s[])
{
    int i, n;
    int c;
    i = n = 0;
    
    if (s[0] == '0' && (tolower(s[1]) == 'x')){
        i = 2;
    }

    for (i; isxdigit((c = toupper(s[i]))); ++i){
        if (c>='A') c-=7;
        n = 16 * n + (c - '0');
    }
    
    return n;
}

int main(){
    printf("%lli", htoi("0xAb58Ec"));
}