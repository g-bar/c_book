// Write a program to determine the ranges of char , short , int , and long
// variables, both signed and unsigned , by printing appropriate values from standard headers
// and by direct computation. Harder if you compute them: determine the ranges of the various
// floating-point types.

#include <stdio.h>
#include <limits.h>
#include <float.h>

int nbits(unsigned long long int n){
    int bytes = 1;
    while (n >>= 1){
        ++bytes;
    }   
    return bytes;
}

//Determine range of char
void char_range(void){
    char n = 0;
    //Wether char is signed or unsigned is implementation dependent
    //If one's complement of 0 is -1 it's signed
    //If one's complement of 0 is a positive number it's unsigned
    if (~n == -1){
        //It's signed
        //Determine the max value (casting to unsigned char is necessary for the right shift operator to pad with 0)
        // i.e  -1 >> 1 gives 11111111
        // and  (unsigned char) -1 >>1 gives 01111111
        n =  (unsigned char) -1 >> 1;
        //Min value is the ones complement of the max value.
        printf("char range: %hhi to %hhi\n", ~n, n);

    } else{
        //If it's unsigned the max value is the one's complement of 0. i.e 11111111 (for a 1 byte size).
        printf("char range: 0 to %hhu\n", ~n);
    }
}

void signed_char_range(void){
    signed char n;
    n =  (unsigned char) -1 >> 1;    
    printf("signed char range: %hhi to %hhi\n", ~n, n);
}

void short_range(void){
    short int n;
    n = (unsigned short) -1 >> 1;    
    printf("short range: %i to %i\n", ~n, n);
}

void int_range(void){
    int n;
    n = (unsigned) -1 >> 1;    
    printf("int range: %i to %i\n", ~n, n);
}

void long_range(void){
    long n;
    n = (unsigned long) -1 >> 1;    
    printf("long range: %li to %li\n", ~n, n);
}

void llong_range(void){
    long long n;
    n = (unsigned long long) -1 >> 1;    
    printf("long long range: %lli to %lli\n", ~n, n);
}

void uchar_range(void){
    unsigned char n;
    n = 0;
    printf("unsigned char range: 0 to %hhu\n", (unsigned char) ~n);
}

void ushort_range(void){
    unsigned short n;
    n = 0;
    printf("unsigned short range: 0 to %hu\n", ~n);
}

void uint_range(void){
    unsigned n;
    n = 0;
    printf("unsigned int range: 0 to %u\n", ~n);
}

void ulong_range(void){
    unsigned long n = 0;
    printf("unsigned long range: 0 to %lu\n", ~n);
}

void ullong_range(void){
    unsigned long long n = 0;
    printf("unsigned long long range: 0 to %llu\n", ~n);
}

void float_range(void){
    /*  Using IEEE754 single precision standard
        https://en.wikipedia.org/wiki/Single-precision_floating-point_format
    */
    char min_bits[] = {0, /* mantissa */
                       0, /* mantissa */
                       128, /*1 0000000 Last bit of exponent and first 7 bits of mantissa*/
                       0 /* 0 0000000 Sign and first 7 bits of exponent*/ };
    char max_bits[] = {255, 255, 127, 127};
    float min, max;

    min = * (float *) min_bits;
    max = * (float *) max_bits;

    printf("float range %g to %g\n", min, max);
}

void double_range(void){
    /* Using IEE754 double precison standard 
      https://en.wikipedia.org/wiki/Double-precision_floating-point_format */
    char min_bits[] = {0,0,0,0,0,0, /* end of mantissa */
                      16, /* 0001 0000 last 4 bits of exponent and first 4 bits of mantissa */
                      0  /* sign and first 7 bits of exponent */};
    char max_bits[] = {255,255,255,255,255,255, 239, 127};
    double min, max;
    
    min = * (double *) min_bits;
    max = * (double *) max_bits;

    printf("double range %g to %g\n", min, max);
}

void ldouble_range(void){
    /* Using x86 extended precision format (80-bit)
       https://en.wikipedia.org/wiki/Extended_precision#x86_extended_precision_format */
    char min_bits[] = {0,0,0,0,0,0,0, /* Rest of fraction */
                      128, /* 1 0000000 Explicit integer bit and first 7 bits of fractional part*/
                      1,/* Last 8 bits of exponent */
                      0 /* Sign and first 7 bits of exponent */};
    char max_bits[] = {255,255,255,255,255,255,255,255,254,127};
    long double min, max;
    
    min = *(long double *) min_bits;
    max = *(long double *) max_bits;
    
    printf("long double range %Lg to %Lg\n", min, max);
}

int main(){

    //Values from limits.h
    printf("Ranges from limits.h\n\n");
    printf("signed char range: %d to %d (%d bits)\n", SCHAR_MIN, SCHAR_MAX, nbits(SCHAR_MAX * 2));
    printf("char range: %d to %d (%d bits)\n", CHAR_MIN, CHAR_MAX, nbits(CHAR_MAX * 2));
    printf("short int range: %d to %d (%d bits)\n", SHRT_MIN, SHRT_MAX, nbits(SHRT_MAX * 2 ));
    printf("int range: %d to %d (%d bits)\n", INT_MIN, INT_MAX, nbits((unsigned long long) (INT_MAX) * 2 ));
    printf("long range %li to %li (%d bits)\n", LONG_MIN, LONG_MAX, nbits((unsigned long long) (LONG_MAX) *2 ));
    printf("long long range %lli to %lli (%d bits)\n", LLONG_MIN, LLONG_MAX, nbits((unsigned long long) (LLONG_MAX) *2 ));
    printf("unsigned char range 0 to %d (%d bits)\n", UCHAR_MAX, nbits(UCHAR_MAX));
    printf("unsigned short range 0 to %d (%d bits)\n", USHRT_MAX, nbits(USHRT_MAX));
    printf("unsigned int range 0 to %u (%d bits)\n", UINT_MAX, nbits(UINT_MAX));
    printf("unsigned long range 0 to %lu (%d bits)\n", ULONG_MAX, nbits(ULONG_MAX));
    printf("unsigned long long range 0 to %llu (%d bits)\n", ULLONG_MAX, nbits(ULLONG_MAX));

    //Computed ranges
    printf("\nComputed ranges\n\n");
    char_range();
    signed_char_range();
    short_range();
    int_range();
    long_range();
    llong_range();
    uchar_range();
    ushort_range();
    uint_range();
    ulong_range();
    ullong_range();
    printf("\n");
    
    //Floating point limits (float.h)
    printf("Floating point number ranges from float.h\n\n");
    printf("float range : %g to %g\n", FLT_MIN, FLT_MAX);
    printf("double range: %g to %g\n", DBL_MIN, DBL_MAX);
    printf("long double range : %Lg to %Lg\n", LDBL_MIN, LDBL_MAX);

    
    //Floating point computed ranges
    printf("\n");
    printf("Floating point computed ranges\n\n");
    float_range();
    double_range();
    ldouble_range();
}
