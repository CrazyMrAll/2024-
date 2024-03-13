#include <iostream>
using namespace std;

void firstmenu(void);
void breakfast(int);
void breakfastmenu(void);
void yx(int);
void yxmenu(void);
double sum1, sum2;

int main()
{
    firstmenu();
    printf("买了这么多美食才花了%.2f。\n",sum1+sum2);
    return 0;
}

void firstmenu()
{
    printf("----- 营业时间 -----\n");
    printf("  1. 早餐\n");
    printf("  2. 中餐\n");
    printf("  3. 晚餐\n");
    printf("  4. 夜宵\n");
    printf("  0. 退出\n");
    printf("请输入选项：");
    int n;
    cin >> n;
    switch (n)
    {
    case 0: break;
    case 1: breakfastmenu();break;
    case 4: yxmenu(); break;
    default :   firstmenu();
    }
}

void breakfastmenu()
{
    int n;
    printf("----- 早餐菜单 -----\n");
    printf(" 1. 油条，0.32\n");
    printf(" 2. 豆浆，0.70\n");
    printf(" 3. 鸡蛋，0.50\n");
    printf(" 4. 豆腐脑，1.50\n");
    printf(" 5. 小包子，0.50\n");
    printf(" 0. 选择结束\n");
    printf("请输入选项：");
    cin >> n;
    breakfast(n);
}

void breakfast (int n)
{
    if ( n>=1 && n<=5) {
        int i;
        double price;
        printf("输入");
        switch (n)
        {
        case 1: printf("油条"); price = 0.32; break;
        case 2: printf("豆浆"); price = 0.70; break;
        case 3: printf("鸡蛋"); price = 0.50; break;
        case 4: printf("豆腐脑"); price = 1.50; break;
        case 5: printf("小包子"); price = 0.50; break;
        }
        printf("数量：");
        cin >> i;
        sum1 += i*price;
        breakfastmenu();
    }
    else if ( n==0 ) {
        printf("早餐合计：%.2f。\n", sum1);    
        firstmenu();
    }
    else
        breakfastmenu();
}

void yxmenu()
{
    int n;
    printf("----- 夜宵菜单 -----\n");
    printf(" 1. 馄饨，2.50\n");
    printf(" 2. 馅饼，1.00\n");
    printf(" 3. 茶鸡蛋，0.60\n");
    printf(" 4. 鸡蛋饼，3.50\n");
    printf(" 0. 选择结束\n");
    printf("请输入选项：");
    cin >> n;
    yx(n);
}

void yx(int n)
{
    if ( n>=1 && n<=4) {
        int i;
        double price;
        printf("输入");
        switch (n)
        {
        case 1: printf("馄饨"); price = 2.50; break;
        case 2: printf("馅饼"); price = 1.00; break;
        case 3: printf("茶鸡蛋"); price = 0.60; break;
        case 4: printf("鸡蛋饼"); price = 3.50; break;
        }
        printf("数量：");
        cin >> i;
        sum2 += i*price;
        yxmenu();
    }
    else if ( n==0 ) {  
        printf("夜宵合计：%.2f。\n", sum2);  
        firstmenu();
    }
    else
        yxmenu();
}