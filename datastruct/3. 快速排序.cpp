#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 100000;
const int cutoff = 5;
queue<int> q;

void Swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void InsertionSort(int *A, int size) {
    for (register int i = 1; i < size; i++) {
        int tmp = A[i];
        int j;
        for (j = i; j && A[j-1] > tmp; j--) 
            A[j] = A[j-1];
        A[j] = tmp;
    }
}

int Median3(int *A, int l, int r) {
    int c = (l + r) / 2;
    if (A[l] > A[c]) Swap(&A[l], &A[c]);
    if (A[l] > A[r]) Swap(&A[l], &A[r]);
    if (A[c] > A[r]) Swap(&A[c], &A[r]);
    Swap(&A[c], &A[r-1]);
    return A[r-1];
}

void Qsort(int *A, int l, int r) {
    int i = l, j = r-1;
    if (l+cutoff <= r) {
        int Pivot = Median3(A, l, r);
        q.push(Pivot);
        while (1) {
            while (A[++i] < Pivot);
            while (A[--j] > Pivot);
            if (i < j) Swap(&A[i], &A[j]);
            else break;
        }
        Swap(&A[i], &A[r-1]);
        Qsort(A, l, i-1);
        Qsort(A, i+1, r);
    } else InsertionSort(A+l, r-l+1);
}

int main()
{
    int cnt = 0, n;
    int num[MAXN];
    while (scanf("%d", &n)) 
        num[cnt++] = n;
    Qsort(num, 0, cnt-1);
    printf("After Sorting:\n");
    for (register int i = 0; i < cnt; i++)
        printf("%d ", num[i]);
    printf("\nMedian3 Value:\n");
    if (q.empty()) printf("none\n");
    else {
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            printf("%d ", t);
        }
        printf("\n");
    }
    return 0;
}