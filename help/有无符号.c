#include <stdio.h>
int main() {
    float a[5] = {1,4,5,6,7};
    float r;    
    int i;
    float result = 0;
    unsigned length;
    length = 0;
    for (i = 0; i < length-1; ++i) {    // i 是有符号数，length 是无符号数
        result += a[i];
        printf("i= %d \n",i);
    }
    printf("r = %f",r);
    return 0;
}