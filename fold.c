
#include <stdio.h>
void foldchars(char *s1, char *s2, int n)
{
    while (n-- > 0)
    {
        if (*s1 >= 65 && *s1 <= 90)
        {
            *s2++ = *s1++ + 32;
        }
    }
}

int main()
{
    char *s1 = "AB";
    char s2[3] = "AB\0";

    foldchars(s1, s2, 2);

    printf("%s\n", s2);
}