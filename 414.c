/* Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t .
(Block structure will help.) */

#include <stdio.h>
#define dprint(x,y) printf(#x "=%d,"  #y "=%d\n", x,y);
#define swap(t,x,y) {t temp; temp = x; x=y; y=temp;}

int main(){
    int x,y;
    x = 0;
    y = 1;
    dprint(x,y);
    if (x<y)
        swap(int, x,y);
    dprint(x,y);
}
