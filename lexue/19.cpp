#include <iostream>
using namespace std;

int main()
{
    int n, m, pay=0, kill=0;
    scanf("%d %d", &n, &m);
    if ( n<=m ) {
        int dragon[n], warrior[m];
        for ( int i=0; i<n; i++ ) {
            scanf("%d", &dragon[i]);
        }
        for ( int i=0; i<m; i++ ) {
            scanf("%d", &warrior[i]);
        }
        for ( int j=0; j<m; j++ ) {
            for ( int i=0; i<m-1; i++ ) {
                if ( warrior[i] > warrior[i+1] ) {
                    int tmp = warrior[i];
                    warrior[i] = warrior[i+1];
                    warrior[i+1] = tmp;
                }
            }
        }
        for ( int i=0; i<n; i++ ) {
            int mid = m/2;
            while ( dragon[i]<=warrior[mid] && mid>0 ) {
                mid /= 2;
            }
            if ( mid==0 ) mid=1;
            for ( int j=mid-1; j<m; j++ ) {
                if ( dragon[i] <= warrior[j] ) {
                    pay += warrior[j];
                    warrior[j] = 0;
                    kill++;
                    break;
                }
            }
        }
    }
    if ( kill<n ) printf("bit is doomed!\n");
    else printf("%d\n", pay);
    return 0;
}