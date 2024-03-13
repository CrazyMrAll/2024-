#include <iostream>
using namespace std;

inline int game(int a, int b) {
    if (a==b) return 0;
    else if (a==0) {
        if (b==1 || b==4) return -1; 
        else return 1;
    } else if (a==1) {
        if (b==0 || b==3) return 1;
        else return -1;
    } else if (a==2) {
        if (b==0 || b==3) return -1;
        else return 1;
    } else if (a==3) {
        if (b==2 || b==4) return 1;
        else return -1;
    }  else if (a==4) {
        if (b==0 || b==1) return 1;
        else return -1;
    }
}

int main()
{
    int N, Na, Nb, aa = 0, bb = 0;
    int A[200], B[200];
    cin >> N >> Na >> Nb;
    for (int i = 0; i < Na; i++)
        cin >> A[i];
    for (int i = 0; i < Nb; i++)
        cin >> B[i];
    for (int i = 0; i < N; i++) {
        int result = game(A[i%Na], B[i%Nb]);
        switch (result)
        {
        case 1 : aa++; break;
        case -1 : bb++; break;
        default: break;
        }
    }   
    cout << aa << " " << bb << endl;
    return 0;
}