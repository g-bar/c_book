// Write a program to determine the ranges of char , short , int , and long
// variables, both signed and unsigned , by printing appropriate values from standard headers
// and by direct computation. Harder if you compute them: determine the ranges of the various
// floating-point types.

#include <stdio.h>
#include <limits.h>

int nbytes(unsigned long long int n){
    int bytes = 1;
    while (n >>= 1){
        ++bytes;
    }
    return bytes;
}

int main(){

    printf("signed char range: %d to %d (%d bytes)\n", SCHAR_MIN, SCHAR_MAX, nbytes(SCHAR_MAX * 2));
    printf("char range: %d to %d (%d bytes)\n", CHAR_MIN, CHAR_MAX, nbytes(CHAR_MAX * 2));
    printf("short int range: %d to %d (%d bytes)\n", SHRT_MIN, SHRT_MAX, nbytes(SHRT_MAX * 2 ));
    printf("int range: %d to %d (%d bytes)\n", INT_MIN, INT_MAX, nbytes((unsigned long long) (INT_MAX) * 2 ));
    printf("long range %li to %li (%d bytes)\n", LONG_MIN, LONG_MAX, nbytes((unsigned long long) (LONG_MAX) *2 ));
    printf("long long range %lli to %lli (%d bytes)\n", LLONG_MIN, LLONG_MAX, nbytes((unsigned long long) (LLONG_MAX) *2 ));
    printf("unsigned char range 0 to %d (%d bytes)\n", UCHAR_MAX, nbytes(UCHAR_MAX));
    printf("unsigned short range 0 to %d (%d bytes)\n", USHRT_MAX, nbytes(USHRT_MAX));
    printf("unsigned int range 0 to %u (%d bytes)\n", UINT_MAX, nbytes(UINT_MAX));
    printf("unsigned long range 0 to %lu (%d bytes)\n", ULONG_MAX, nbytes(ULONG_MAX));
    printf("unsigned long long range 0 to %llu (%d bytes)\n", ULLONG_MAX, nbytes(ULLONG_MAX));

}
