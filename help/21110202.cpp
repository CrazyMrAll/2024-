#include <stdio.h>
 
int main() {
    char arr;
    float a = 0.0, e = 0.0, i = 0.0, o = 0.0, u = 0.0;
    float cnt = 0.0;
    while ( scanf("%c", &arr) && arr!='\n' ) {
        switch ( arr ) 
        {
            case 'A' :
            case 'a' : a++;break;
            case 'E' :
            case 'e' : e++;break;
            case 'I' :
            case 'i' : i++;break;
            case 'U' :
            case 'u' : u++;break;
            case 'O' :
            case 'o' : o++;break;
 
        }
        cnt++;
    }
    printf("%.1f%%,%.1f%%,%.1f%%,%.1f%%,%.1f%%", a * 100.0 / cnt, e * 100.0 / cnt, i * 100.0 / cnt, o * 100.0 / cnt,
           u * 100.0 / cnt);
    return 0;
}