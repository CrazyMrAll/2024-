#include <iostream>
using namespace std;

struct node {
    bool flag = 0;
    node *left = NULL, *right = NULL;
};

int main()
{
    char s[100000];
    int T;
    scanf("%d", &T);
    node *head = new node;
    bool flag = 0;
    for (register int g = 0; g < T; g++) {
        scanf("%s", s);
        node *t = head;
        for (register int i = 0; s[i] != '\0'; i++) {
            if (!t->flag) {
                if (s[i] == '0') {
                    if (!t->left) t->left = new node;
                    t = t->left;
                } else {
                    if (!t->right) t->right = new node;
                    t = t->right;
                }
                if (s[i+1] == '\0') t->flag = 1;
            } else {
                flag = 1;
                break;
            }
        }
        if (t->left) flag = 1;
        if (t->right) flag = 1;
        if (flag) break;
    }
    if (flag) printf("%s\n", s);
    else printf("YES\n");
    return 0;
}