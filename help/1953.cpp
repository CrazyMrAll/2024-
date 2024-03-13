#include <iostream>
using namespace std;

int main()
{
   int cnt = 0;
   for ( int i=1; i<=9; i++ ) {
        int a, b, c;
        for ( int j=1; j<=9; j++ ) {
            if ( j!=i ) {
                for ( int k=1; k<=9; k++ ) {
                    if ( k!=i && k!=j ) {
                        a = i*100 + j*10 + k;
                        for ( int bi=i+1; bi<=9; bi++ ) {
                            if ( bi!=i && bi!=j && bi!=k ) {
                                    for ( int bj=1; bj<=9; bj++ ) {
                                    if ( bj!=i && bj!=j && bj!=k && bj!=bi ) {
                                        for ( int bk=1; bk<=9; bk++ ) {
                                                if ( bk!=i && bk!=j && bk!=k && bk!=bi && bk!=bj ) {
                                                    b = bi*100 + bj*10 + bk;
                                                for ( int ci=bi+1; ci<=9; ci++ ) {
                                                    if ( ci!=i && ci!=j && ci!=k && ci!=bi && ci!=bj && ci!=bk ) {
                                                            for ( int cj=1; cj<=9; cj++ ) {
                                                            if ( cj!=i && cj!=j && cj!=k && cj!=bi && cj!=bj && cj!=bk && cj!=ci ) {
                                                                for ( int ck=1; ck<=9; ck++ ) {
                                                                        if ( ck!=i && ck!=j && ck!=k && ck!=bi && ck!=bj && ck!=bk && ck!=ci && ck!=cj ) {
                                                                            c = ci*100 + cj*10 + ck;
                                                                            if ( a+b+c==1953 ) {printf("%d+%d+%d=1953\n", a, b, c);cnt++;}
                                                                            else break;
                                                                        }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
   printf("Total:%d\n", cnt);
   return 0;
}