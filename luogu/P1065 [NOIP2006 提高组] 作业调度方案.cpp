#include <iostream>
using namespace std;

int item[20][20], timetable[20][20], order[20], itemtime[20];
//依次为生产需要用的机器，所用的时间，每个工件加工到了哪一步，每个工作累计的工作时间
struct state{
    int eachtime[400][2];
    int blank[400][2];
};
state machine[20];
int main()
{
    int m, n, workingline[400];//工作顺序
    cin >> m >> n;
    for (int i = 0; i < m * n; i++)
        cin >> workingline[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> item[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> timetable[i][j];
    }
    for (int i = 0; i < m * n; i++) {
        int nowitem = workingline[i] - 1;
        int noworder = order[nowitem]++;
        int nowtime = timetable[nowitem][noworder];
        int nowmachine = item[nowitem][noworder] - 1;
        state *p = &machine[nowmachine];
        int machinetime = 0;
        int maxi, inserti;
        for (int i = m * n - 1; i >= 0; i--) {
            if (p->eachtime[i][1]) {
                machinetime = p->eachtime[i][1];
                break;
            }  
        }  
        if (machinetime <= itemtime[nowitem]) {
            if (machinetime < itemtime[nowitem]) {//前插空格
                for (int i = 0; i < m * n; i++) {
                    if (!p->blank[i][0] && !p->blank[i][1]) {
                        p->blank[i][0] = machinetime;
                        p->blank[i][1] = itemtime[nowitem];
                        machinetime = itemtime[nowitem];
                        break;
                    }
                }
            }
            for (int i = 0; i < m * n; i++) {
                if (!p->eachtime[i][0] && !p->eachtime[i][1]) {
                    p->eachtime[i][0] = machinetime;
                    p->eachtime[i][1] = p->eachtime[i][0] + nowtime;
                    break;
                }
            } 
        } else {
            bool flag = 1;
            for (int i = 0; i < m * n; i++) {
                if (!p->blank[i][0] && !p->blank[i][1]) {
                    flag = 0;
                    break;
                }
                else if (p->blank[i][1] - p->blank[i][0] >= nowtime && 
                        p->blank[i][1] >= nowtime + itemtime[nowitem] ) {
                    //之前这里漏了后面的且条件，有空就插是不对的
                    //分割空格
                    int max = (p->blank[i][0] > itemtime[nowitem]) ? p->blank[i][0] : itemtime[nowitem];
                    //哪个时间更后面
                    int left = max;
                    int right = left + nowtime;
                    if (max != p->blank[i][0]) {
                        //空格后移并且前插空格
                        // int maxi, 
                        inserti = i;
                        for (int i = m * n - 1; i >= 0; i--) {
                            if (p->blank[i][1]) {
                                maxi = i;
                                break;//连漏两个break我是真的谢
                            }
                        }
                        for (int i = maxi + 1; i > inserti; i--) {
                            p->blank[i][0] =  p->blank[i-1][0];
                            p->blank[i][1] =  p->blank[i-1][1];
                        }
                        if (right < p->blank[i][1]) {
                            p->blank[i+1][0] = right;//只需要更改左端
                        }
                        p->blank[i][1] = max;//只需要更改右端    
                    }
                    if (right < p->blank[i][1]) {
                        p->blank[i][0] = right;//只需要更改左端
                    }
                    //eachtime后移
                    // int maxi, inserti;
                    for (int i = m * n - 1; i >= 0; i--) {
                        if (p->eachtime[i][1]) {
                            maxi = i;
                            break;//之前漏写break;
                        }
                    }
                    for (int i = 0; i < m * n; i++) {
                        if (p->eachtime[i][0] >= left) {
                            inserti = i;
                            break;
                        }
                    }
                    for (int i = maxi + 1; i > inserti; i--) {
                        p->eachtime[i][0] =  p->eachtime[i-1][0];
                        p->eachtime[i][1] =  p->eachtime[i-1][1];
                    }
                    //填充当前时间
                    p->eachtime[inserti][0] = left;
                    p->eachtime[inserti][1] = right;
                    break;
                }
            }
            //如果没空格直接插后面
            if (!flag) {
                for (int i = 0; i < m * n; i++) {
                    if (!p->eachtime[i][0] && !p->eachtime[i][1]) {
                        p->eachtime[i][0] = machinetime;
                        p->eachtime[i][1] = p->eachtime[i][0] + nowtime;
                        inserti = i;
                        break;
                    }
                } 
            }
        }
        itemtime[nowitem] = p->eachtime[inserti][1];

        cout << "round " << i + 1 << endl;
        cout << "itemtime = " << itemtime[nowitem] << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                    cout << machine[i].eachtime[j][0] << " "
                        << machine[i].eachtime[j][1] << "\t";
            }
            cout << endl;
            for (int j = 0; j < m; j++) {
                    cout << machine[i].blank[j][0] << " "
                        << machine[i].blank[j][1] << "\t";
            }
            cout << endl;
            cout << endl;
        }

    }
    int maxtime = 0;
    for (int i = 0; i < n; i++) {
        for (int j = m * n - 1; j >= 0; j--) {
            if (machine[i].eachtime[j][1]) {
                if (machine[i].eachtime[j][1] > maxtime) 
                    maxtime = machine[i].eachtime[j][1];
                break;
            }
        }
    }
    cout << maxtime;
    return 0;
}

//一些反思：1变量名不够直观2没有设计好函数在十几个小时后放弃。。。