#include <iostream>
using namespace std;

int CombineNum(int up, int down) {
    int C = down;
    for ( int i=2; i<=up; i++ ) {
        C *= down-i+1;
        C /= i;
    }
    return C;
}

int main()
{
    int n;
    scanf("%d", &n);
    int num[26][27];
    for ( int i=0; i<26; i++ ) 
        for ( int j=0; j<27; j++ )
            num[i][j] = 0;
    for ( int i=0; i<n; i++ ) {
        char s[11];
        scanf("%s", s);
        bool flag = 1;
        int len = 1;
        for ( int i=0; s[i+1]!='\0'; i++ ) {
            if ( s[i]>=s[i+1] ) {flag=0;break;}
            len++;
        }
        if ( flag ) {
            int sum = 0;
            for ( int i=0; i<len; i++ ) {
                if ( !num[i+1][26] ) num[i+1][26]=CombineNum(i+1,26);
                sum += num[i+1][26];
                if ( !num[len-i][26-(s[i]-'a'+1)] ) num[len-i][26-(s[i]-'a'+1)]=CombineNum(len-i,26-(s[i]-'a'+1));
                sum -= num[len-i][26-(s[i]-'a'+1)];
            }
            printf("%d\n", sum);
        } else printf("0\n");
    }
    return 0;
}