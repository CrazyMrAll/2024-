#include <stdio.h>
// S12=0, D11=1, C10=2, H1=3……
int rule[13]={-50, -2, -3, -4, -5, -6, -7, -8, -9, -10, -20, -30, -40};
int main()
{
    while(1) {
        bool cards[4][16]={{0}};
        int num[4], score[4]={0}, cnt = 0, state[4]={0};
        for ( int i=0; i<4; i++ ) {
            scanf("%d", &num[i]);
            for ( int j=0; j<num[i]; j++ ) {
                char t[4];
                scanf("%s", t);
                if ( t[0]=='S' ) cards[i][0]=1;
                else if ( t[0]=='D' ) cards[i][1]=1;
                else if ( t[0]=='C' ) cards[i][2]=1;
                else {
                    int tmp = 0;
                    for ( int i=1; t[i]!='\0'; i++ )
                        tmp = tmp*10 + t[i]-'0';
                    cards[i][tmp+2]=1;
                }
            }
            if ( num[i]==0 ) cnt++;
        }
        if ( cnt==4 ) break;
        for ( int i=0; i<4; i++ ) {
            if ( num[i]==16 ) score[i]=1000;
            else {
                bool flag = 1;
                for ( int j=3; j<16; j++ ) {
                    if (!cards[i][j]) flag = 0;
                    else score[i]+=rule[j-3];
                }
                if ( flag ) score[i] = 200;
                if (cards[i][0]) state[i]+=1;
                if (cards[i][1]) state[i]+=2;
                if (cards[i][2]) state[i]+=4;
                if ( state[i]==1 ) score[i]-=100;
                else if ( state[i]==2 ) score[i]+=100;
                else if ( state[i]==3 && flag ) score[i]=500;
                else if ( state[i]==4 ) {
                    if (num[i]==1) score[i]=50;
                    else score[i]*=2;
                }
                else if ( state[i]==5 ) score[i]=2*(score[i]-100);
                else if ( state[i]==6 ) score[i]=2*(score[i]+100);
            } 
        }
        for ( int i=0; i<4; i++ ) {
            if (score[i]>0) printf("+%d", score[i]);
            else printf("%d", score[i]);
            if (i!=3) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}