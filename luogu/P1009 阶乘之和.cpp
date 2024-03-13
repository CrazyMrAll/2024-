#include<iostream>
using namespace std;
#define MAXN 10000

int main ()
{
    int n;
    cin >> n;
    int now[MAXN], tmp[MAXN], ans[MAXN], final[MAXN];
    now[MAXN] = tmp[MAXN] = ans[MAXN] = final[MAXN] = {0};
    int lennow = 1, lentmp = 1;
    tmp[1] = 1;
    for ( int i=1; i<=n; i++ ) {
        now[1] = i % 10; 
        if ( i>=10 ) {
            now[2] = i / 10;
            lennow = 2;
        }
        for ( int i=1; i<=lentmp; i++ )
            for( int j=1; j<=lennow; j++ )
                ans[i+j-1] += tmp[i] * now[j];
        
        /*cout << "i=" << i << endl;
        printf("lennow=%d lentmp=%d\n",lennow, lentmp);
        for ( int i=1; i<lennow+lentmp; i++ ) 
            cout << "ans[" << i << "]=" << ans[i] << " ";
        cout << endl;*/

        for ( int i=1; i<=lennow+lentmp; i++ ) {
            if ( ans[i]>9 ) {
                ans[i+1] += ans[i] / 10;
                ans[i] %= 10;
            }
            // printf("ans[%d]=%d ", i, ans[i]);
            tmp[i] = ans[i];
            ans[i] = 0;
            final[i] += tmp[i];
            if ( final[i]>9 ) {
                final[i+1]++;
                final[i] %= 10;
            }
        } 
        // printf("\n");
        int len = lennow + lentmp;
        while ( tmp[len]==0 && len>1 ) len--;
        lentmp = len;
    }
	int len = lennow + lentmp;
    while ( final[len]==0 && len>1 ) len--;
    for ( int i=len; i>=1; i-- ) cout << final[i];
    return 0;
}