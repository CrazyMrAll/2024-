#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, b, ans = 0;
    scanf("%d", &n);
    vector<int> min_heap(n);
    for (register int i = 0; i < n; i++)
        scanf("%d", &min_heap[i]);
    make_heap(min_heap.begin(), min_heap.end(), greater<int>());
    while (min_heap.size() > 1) {
        a = min_heap[0];
        pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
        min_heap.pop_back();
        b = min_heap[0];
        pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
        min_heap.pop_back();
        // printf("pop %d %d\n", a, b);
        // printf("push %d\n", a+b);
        min_heap.push_back(a+b);
        push_heap(min_heap.begin(), min_heap.end(), greater<int>());
        ans += a+b;
    }
    printf("WPL=%d\n", ans);
    return 0;
}