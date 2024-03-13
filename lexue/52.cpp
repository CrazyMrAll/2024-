#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 500

char ans[MAXN]; 
class bigNum
{
friend char* operator+(const bigNum &a, const bigNum &b);
friend char* operator-(const bigNum &a, const bigNum &b);

private:
    char* num;
public:
    bigNum();
    ~bigNum();
    void Input(char*);
};

bigNum::bigNum()
{
    num = new char[MAXN];
}

bigNum::~bigNum()
{
    delete num;
}

void bigNum::Input(char *p) {
    strcpy(num, p);
}

char* operator+(const bigNum &a, const bigNum &b){
    int lena = strlen(a.num), lenb = strlen(b.num);
    int t, now, next = 0;
    if ( lena<lenb ) {
        for ( int i=lenb-1; i>=0; i-- ) {
            t = ((i>=lenb-lena) ? a.num[lena-lenb+i]-'0' : 0) + b.num[i]-'0';
            now = (t+next) % 10;
            next = (t+next) / 10;
            ans[lenb-1-i] = now + '0';
        }        
    } else {
        for ( int i=lena-1; i>=0; i-- ) {
            t = ((i>=lena-lenb) ? b.num[lenb-lena+i]-'0' : 0) + a.num[i]-'0';
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

char* operator-(const bigNum &a, const bigNum &b){
    if ( strcmp(a.num,b.num)==0 ) {ans[1] = '\0'; return ans;}
    else {
        int lena = strlen(a.num), lenb = strlen(b.num);
        bool flag = 0;
        if ( (strcmp(a.num,b.num)<0 && lena==lenb) || lena<lenb ) {
            flag = 1;
            {char c[MAXN]; strcpy(c,b.num); strcpy(b.num,a.num); strcpy(a.num,c);}
            {int t = lena; lena = lenb; lenb = t;}
        }
        bool next = 0;
        for ( int i=lena-1; i>=0; i-- ) {
            int t = a.num[i]-'0' - ((i<lena-lenb) ? 0 : b.num[lenb-lena+i]-'0');
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
    cin >> n;
    for ( int i=0; i<n; i++ ) {
        ans[0] = '0';
        char origin[2*MAXN];
        bool flag = 1; // 加减
        cin >> origin;
        int len = strlen(origin), sign = 0;
        for ( int i=0; i<len; i++ ) {
            if ( origin[i]=='+' ) {
                flag = 1;
                sign = i + 1;
                origin[i] = '\0';
            } else if ( origin[i]=='-' ) {
                flag = 0;
                sign = i + 1;
                origin[i] = '\0';
            }
        }
        bigNum a, b;
        a.Input(origin);
        b.Input(origin+sign);
        if ( flag ) cout << a+b << endl; 
        else cout << a-b << endl;
    }
    return 0;
}