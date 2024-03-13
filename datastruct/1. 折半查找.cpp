#include <iostream>
using namespace std;
struct node {
    int key, order;
};

void inline InsertionSort(struct node *A, int size) {
    for (register int i = 1; i < size; i++) {
        node tmp = A[i];
        int j;
        for (j = i; j && A[j-1].key > tmp.key; j--) 
            A[j] = A[j-1];
        A[j] = tmp;
    }
}

int main()
{
    int n, X;
    scanf("%d", &n);
    node num[n];
    for (register int i = 0; i < n; i++)
        scanf("%d%d", &num[i].key, &num[i].order);
    scanf("%d", &X);
    InsertionSort(num, n);
    for (register int i = 0; i < n; i++)
        printf("(%d %d)", num[i].key, num[i].order);
    printf("\n");
    int l = 0, r = n-1;
    while (l < r-1) {
        int mid = (l + r) / 2;
        if (num[mid].key == X) {
            printf("(%d %d)\n", num[mid].key, num[mid].order);
            return 0;
        } else if (num[mid].key < X) l = mid; 
        else r = mid;
    }
    printf("error\n");
    return 0;
}