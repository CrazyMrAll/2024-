#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 501

char *Add (char *a, char *b, char *ans) {
    int lena = strlen(a), lenb = strlen(b);
    int t, now, next = 0;
    if ( lena<lenb ) {
        for ( int i=lenb-1; i>=0; i-- ) {
            t = ((i>=lenb-lena) ? a[lena-lenb+i]-'0' : 0) + b[i]-'0';
            now = (t+next) % 10;
            next = (t+next) / 10;
            ans[lenb-1-i] = now + '0';
        }        
    } else {
        for ( int i=lena-1; i>=0; i-- ) {
            t = ((i>=lena-lenb) ? b[lenb-lena+i]-'0' : 0) + a[i]-'0';
            now = (t+next) % 10;
            next = (t+next) / 10;
            ans[lena-1-i] = now + '0';
        }
    }
    int max = (lena>lenb) ? lena : lenb;   
    if ( next ) {ans[max]='1';ans[max+1] = '\0';}
    else ans[max] = '\0';
    int len = strlen(ans);
    for ( int i=0; i<len/2; i++ ) {
        char t = ans[i];
        ans[i] = ans[len-1-i];
        ans[len-1-i] = t;
    }
    return ans;
}

char *Sub (char *a, char *b, char *ans) {
    if ( strcmp(a,b)==0 ) {ans[1] = '\0'; return ans;}
    else {
        int lena = strlen(a), lenb = strlen(b);
        bool flag = 0;
        if ( (strcmp(a,b)<0 && lena==lenb) || lena<lenb ) {
            flag = 1;
            {char c[MAXN]; strcpy(c,b); strcpy(b,a); strcpy(a,c);}
            {int t = lena; lena = lenb; lenb = t;}
        }
        bool next = 0;
        for ( int i=lena-1; i>=0; i-- ) {
            int t = a[i]-'0' - ((i<lena-lenb) ? 0 : b[lenb-lena+i]-'0');
            ans[i+1] = t - next + '0';
            if ( t-next<0 ) {
                next = 1;
                ans[i+1]+=10;
            } else next = 0;
        }
        ans[lena+1] = '\0';
        int cnt = 1;
        for ( ; ; cnt++ )
            if ( ans[cnt]!='0' ) break;
        if ( flag ) ans[cnt-flag] = '-';
        return &ans[cnt-flag];
    }    
}

int main()
{
    int n;
    scanf("%d", &n);
    char a[MAXN], b[MAXN], c[2*MAXN];
    for ( int i=0; i<n; i++ ) {
        bool flag = 1;
        char ans[502];
        ans[0] = '0';
        cin >> c;
        int len = strlen(c), j = 0;
        bool done = 1;
        for ( int i=0; i<len; i++ ) {
            if ( c[i]=='+' ) {a[j]='\0';j = done = 0;}
            else if ( c[i]=='-' ) {a[j]='\0';j = flag = done = 0;}
            else {
                if ( done ) a[j++] = c[i];
                else b[j++] = c[i];
            }
            if ( i==len-1 ) b[j] = '\0';
        }
        if ( flag ) printf("%s\n", Add(a,b,ans));
        else printf("%s\n", Sub(a,b,ans));
    }
    return 0;
}