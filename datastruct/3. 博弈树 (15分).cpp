#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

struct node {
    char ch;
    node *son = NULL;
    node *brother = NULL;
};
char tmp[100];
int index = 0;
node *tp;
node *root;
bool game = 0;//0 means start, 1 menas gaming

node *Build() {
    node *t = NULL;
    while (1) {
        // printf("scan %c\n", tmp[index]);
        if (tmp[index] == '(') {
            index++;
            // printf("new %c\n", tmp[index]);
            t = new node;
            t->ch = tmp[index];
            // printf("find %c's son\n", t->ch);
            t->son = Build();
            // printf("now %c\n", tmp[index]);
            // if (t->son) printf("%c's son is %c\n", t->ch, t->son->ch);
            // else printf("%c has no son\n", t->ch); 
            // printf("find %c's brother\n", t->ch);
            t->brother = Build();
            // if (t->brother) printf("%c's brother is %c\n", t->ch, t->brother->ch);
            // else printf("%c has no brother\n", t->ch);
            break;
        } else if (tmp[index] == ')') {
            index++;
            break;
        } else if (tmp[index] == '\0') {
            index--;
            break;
        }
        index++;
    }
    return t;
}

void inline Print(node *t) {
    printf("%c\n", t->ch);
    if (t->son) Print(t->son);
    if (t->brother) Print(t->brother);
}

int GetHeight(node *t) {
    if (!t) return 0;
    else {
        int max = 0, h;
        node *tmp = t->son;
        while (tmp) {
            h = GetHeight(tmp) + 1;
            if (max < h) max = h;
            tmp = tmp->brother;
        }
        return max;
    }
}

// depth is the dis from t to the node first input.
bool check(node *t, int depth) {
    if (!t) {
        return depth % 2;
    } else {
        // printf("check = %c, depth = %d\n", t->ch, depth);
        bool flag = 1;
        if (check(t->son, depth+1)) {
            // printf("%c's good\n", t->ch);
            t = t->son;
            depth++;
            while (t) {
                if (!check(t->son, depth+1)) {
                    // printf("%c's NOT good\n", t->ch);
                    flag = 0;
                    break;
                }
                t = t->brother;
            }
        } else flag = 0;
        return flag;
    }
}

// t is player's choice. NULL represents computer goes first.
void inline move(node *t) {
    if (!t) t = root;
    node *tmp = t->son;
    int n = 0;//num of can win
    bool flag;//is this node can win
    int m = INT_MAX, M = INT_MIN, h;//min and max
    queue<node *> win;
    queue<node *> lose;
    while (tmp) {
        flag = check(tmp, 0);
        n += flag;
        h = GetHeight(tmp);
        if (flag) {
            // printf("%c is win\n", tmp->ch);
            if (h < m) m = h;
            win.push(tmp);
        } else {
            // printf("%c is lose\n", tmp->ch);
            if (M < h) M = h;
            lose.push(tmp);
        } 
        tmp = tmp->brother;
    }
    // printf("m = %d, M = %d\n", m, M);
    if (n) {
        while (!win.empty()) {
            tmp = win.front();
            h = GetHeight(tmp);
            if (h == m) {
                tp = tmp;
                printf("computer: %c\n", tmp->ch);
                if (!tmp->son) {
                    game = 0;
                    printf("Sorry, you lost.\n");
                }
                break;
            }
            win.pop();
        }
    } else {
        while (!lose.empty()) {
            tmp = lose.front();
            h = GetHeight(tmp);
            if (h == M) {
                tp = tmp;
                printf("computer: %c\n", tmp->ch);
                break;
            }
            lose.pop();
        }
    }
}

node *find(char x, node *root) {
    if (root->ch == x) return root;
    node *t = NULL;
    if (root->son) t = find(x, root->son);
    if (!t && root->brother) t = find(x, root->brother);
    return t; 
}

void inline Player(node *root) {
    char ch;
    while (1) {
        printf("player:\n");
        scanf("\n%c", &ch);
        tp = find(ch, root);
        if (!tp) printf("illegal move.\n");
        else {
            node *tmp = root->son;
            bool flag = 1;
            while (tmp) {
                if (tp == tmp) {
                    flag = 0;
                    break;
                }
                tmp = tmp->brother;
            }
            if (flag) printf("illegal move.\n");
            else {
                if (!tp->son) {
                    printf("Congratulate, you win.\n");
                    game = 0;
                }
                break;
            }
        }
    }
}

int main()
{
    scanf("%s", tmp);
    root = Build();
    Print(root);
    char ch;
    bool flag;
    while (1) {
        // Start
        printf("Who play first(0: computer; 1: player )?\n");
        scanf("%d", &flag);
        // Game
        tp = NULL;
        game = 0;
        if (flag) Player(root);
        game = 1;
        while (game) {
            move(tp);
            if (game) Player(tp);
        }
        // Continue?
        printf("Continue(y/n)?\n");
        scanf("\n%c", &ch);
        if (ch == 'n') break;
    }
    return 0;
}