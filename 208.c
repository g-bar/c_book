// Write a function rightrot(x,n) that returns the value of the integer x rotated
// to the right by n positions.

int rightrot(int x, int n){
        return (x & ~(~0<<n)) << sizeof x * 8 - n | (unsigned) x>>n;
}
