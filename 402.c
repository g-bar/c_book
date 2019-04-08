#include <ctype.h>
/* Exercise 4-2. Extend atof to handle scientific notation of the form
    123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent. */

double _atof(char s[])
{
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    
    return sign * val / power;
}

double atof(char s[]){
    double val;
    int i, sign, exponent;

    val = _atof(s);
    
    for (i = 0;  s[i] != '\0' && s[i] != 'e' && s[i] != 'E'; i++){
        ;
    }
        
    if (s[i] == '\0'){
        return val;
    } else{
        i++;
    }

    exponent = (int) _atof(&s[i]);
    sign = exponent<0 ? -1 : 1;
    exponent = exponent<0 ? exponent/-1 : exponent;

    for(i=0; i<exponent;i++){
        val = (sign == -1) ? val/10 : val*10;  
    }
    
    return val;
}