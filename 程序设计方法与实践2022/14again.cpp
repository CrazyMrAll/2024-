#include <iostream>
using namespace std;
const int MAXN = 100005;
struct size {
    int a, b, c;
} item[MAXN];

int getmin(int i) {
    int min = item[i].a;
    if (min > item[i].b) min = item[i].b;
    if (min > item[i].c) min = item[i].c;
    return min;
}

int check(int i, int j) {
    if (item[i].a == item[j].a && 
        item[i].b == item[j].b && 
        item[i].c == item[j].c) return 1;
    else if (item[i].a == item[j].a && 
             item[i].b == item[j].b) return 2;
    else if (item[i].a == item[j].a &&
             item[i].c == item[j].c) return 3;
    else if (item[i].b == item[j].b && 
             item[i].c == item[j].c) return 4;
    else return 0;
}

int min(int a, int b, int c) {
    if (a < b) 
        if (a < c) return a;
        else return c;
    else 
        if (b < c) return b;
        else return c;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &item[i].a, &item[i].b, &item[i].c);
    int solomax = 0, doublemax = 0, maxi = -1, maxj = -1;
    for (int i = 0; i < n; i++) {
        int min = getmin(i);
        if (min > solomax) solomax = min;
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int situation = check(i, j);
            int min, t;
            switch (situation)
            {
                case 0: break;
                case 1: {
                    int min = getmin(i);
                    if (doublemax < min*2) {
                        doublemax = 2*min;
                        maxi = i+1;
                        maxj = j+1;
                    }
                    break;
                } case 2: {
                    t = item[i].c + item[j].c;
                    min = (t, item[i].a, item[i].b);
                    if (doublemax < min) {
                        doublemax = min;
                        maxi = i+1;
                        maxj = j+1;
                    }
                    break;
                } case 3: {
                    t = item[i].b + item[j].b;
                    min = (t, item[i].a, item[i].c);
                    if (doublemax < min) {
                        doublemax = min;
                        maxi = i+2;
                        maxj = j+1;
                    }
                    break; 
                } case 4: {
                    t = item[i].a + item[j].a;
                    min = (t, item[i].b, item[i].c);
                    if (doublemax < min) {
                        doublemax = min;
                        maxi = i+1;
                        maxj = j+1;
                    }
                    break;
                }
                    
            }
        }
    }
    // printf("%d\n", solomax);
    // printf("%d\n", doublemax);
    if (solomax > doublemax) printf("1\n%d\n", solomax);
    else printf("2\n%d %d\n", maxi, maxj);
    return 0;
}