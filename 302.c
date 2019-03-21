/* Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s . Use a switch . Write
a function for the other direction as well, converting escape sequences into the real characters. */

void escape(char s[], char t[])
{
    int i, j;
    char c;
    i = j = 0;
    while ((c = t[j++]) != '\0'){
        switch (c){
            case '\n':
                s[i++] = '\\';
                s[i++] = 'n';
                break;
            case '\t':
                s[i++] = '\\';
                s[i++] = 't';
                break;
            default:
                s[i++] = c;
                break;
        }
    }
    
    s[i] = '\0'; //terminate s
}

void real(char s[], char t[])
{
    int i, j;
    char c1, c2;
    
    for (i = j = 0; c2 = t[j+1], (c1 = t[j]) != '\0' ; j++){
        switch (c1){
            case '\\':
                switch (c2){
                    case 'n':
                        s[i++] = '\n';
                        j++;
                        break;
                    case 't':
                        s[i++] = '\t';
                        j++;
                        break;
                }
                break;
            default:
                s[i++] = c1;
                break;
        }

    }
    
    s[i] = '\0'; //terminate s
    
}
