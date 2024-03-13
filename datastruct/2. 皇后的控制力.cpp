#include <iostream>
using namespace std;
const int MAXN = 10;
bool l[MAXN], r[MAXN], lefts[2*MAXN], rights[2*MAXN];
int cnt;
int N, M;

void queen(int line, int num) {
    // printf("line = %d, num = %d\n", line, num);
    if (!num) {
        for (register int i = 0; i < N; i++)
            for (register int j = 0; j < N; j++) 
                if (!r[i] && !l[j] && !lefts[i+j] && !rights[N-1-i+j]) return;
        cnt++;
    } else {
        for (register int i = line; i < N-num+1; i++) {//从N改成N-num+1快了很多
            for (register int j = 0; j < N; j++) {
                if (!r[i] && !l[j] && !lefts[i+j] && !rights[N-1-i+j]) {
                    r[i] = l[j] = lefts[i+j] = rights[N-1-i+j] = 1;
                    queen(i, num-1);
                    r[i] = l[j] = lefts[i+j] = rights[N-1-i+j] = 0;
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    queen(0, M);
    printf("%d\n", cnt);
    return 0;
}