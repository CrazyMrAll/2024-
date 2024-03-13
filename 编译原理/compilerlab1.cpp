#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

const int MAXN = 50;
string vname[MAXN];
int vnum[MAXN];
int vi = 1;
stack<int> ns;
stack<char> os;

// 定义操作符的优先级
unordered_map<char, int> precedence = {
    {'=', 0},  // 赋值运算符的优先级较低
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'(', 3},  // 左括号的优先级最高
    {')', 3}   // 右括号的优先级最低
};

// // 定义操作符的优先级
// unordered_map<string, int> precedence = {
//     {"=", 0},
//     {"+", 1},
//     {"-", 1},
//     {"*", 2},
//     {"/", 2},
//     {"(", 3},
//     {")", 3}
// };

// 计算二元操作符的结果
int calculate(int a, int b, char op) {
    cout << "pop ebx" << endl;
    cout << "pop eax" << endl;
    switch (op) {
        case '+':
            cout << "add eax, ebx" << endl;
            return a + b;
        case '-':
            cout << "sub eax, ebx" << endl;
            return a - b;
        case '*':
            cout << "imul eax, ebx" << endl;
            return a * b;
        case '/':
            cout << "cdq" << endl;
            cout << "idiv eax, ebx" << endl;
            return a / b;
        default:
            return 0; // 处理错误情况
    }
}

int main(int argc, char *argv[])
{
    const char* inputFilePath = argv[1];
    // 打开
    ifstream inputFile(inputFilePath);
    // 逐行读取文件内容
    string word;
    while (inputFile >> word) {
        if (word == "int") {
            inputFile >> word;
            vname[vi] = word;
            cout << "mov DWORD PTR [ebp-" << 4*vi++ << "], 0" << endl;
            inputFile >> word; // 吞掉行末尾分号
        } else if (word == "return") {
            inputFile >> word;
            int ri;
            for (ri = 1; ri <= vi; ri++)
                if (vname[ri] == word) 
                    break;
            cout << "mov eax, DWORD PTR [ebp-" << 4*ri << "]" << endl;
            break;
        } else {
            int ri;
            for (ri = 1; ri <= vi; ri++)
                if (vname[ri] == word) 
                    break;
            // 吞掉等号
            inputFile >> word;
            int result;
            bool flag1 = 0; // 遇见过数字才变成1
            bool flag2 = 0; // 打印过数字移到寄存器的语句才变成1
            int wordi = 0;
            while (inputFile >> word) {
                wordi++;
                // 把上次的数字移到寄存器的语句打印出来
                if (flag1 && !flag2 && wordi > 2) {
                    flag1 = 0;
                    cout << "mov eax, " << result << endl;
                    cout << "push eax" << endl;
                    flag2 = 1;
                }
                if (word == ";") {
                    // 处理剩余的操作符和操作数
                    while (!os.empty()) {
                        char op = os.top();
                        os.pop();
                        int b = ns.top();
                        ns.pop();
                        int a = ns.top();
                        ns.pop();
                        ns.push(calculate(a, b, op)); // 计算并将结果入栈
                        cout << "push eax" << endl;
                    }
                    result = ns.top();
                    ns.pop();
                    if (wordi == 2) {
                        cout << "mov DWORD PTR [ebp-" << 4*ri << "], " << result << endl;
                        vnum[ri] = result;
                    } else {
                        cout << "pop eax" << endl;
                        cout << "mov DWORD PTR [ebp-" << 4*ri <<"], eax" << endl;
                    }
                    break;
                } else {
                    int ni;
                    bool flag = 0; // 是数字或者操作符则为0，变量为1
                    for (ni = 1; ni <= vi; ni++) {
                        // cout << vname[ni] << " and " << word << endl;
                        if (vname[ni] == word) {
                            flag = 1;
                            break;
                        }
                    }
                    char ch = word[0];
                    if (flag) {
                        cout << "mov eax, DWORD PTR [ebp-" << 4*ni << "]" << endl;
                        ns.push(vnum[ni]);
                        cout << "push eax" << endl;
                    } else if (ch == '(') {
                        os.push(ch); // 左括号入栈
                    } else if (ch == ')') {
                        while (!os.empty() && os.top() != '(') {
                            char op = os.top();
                            os.pop();
                            int b = ns.top();
                            ns.pop();
                            int a = ns.top();
                            ns.pop();
                            ns.push(calculate(a, b, op)); // 计算并将结果入栈
                            cout << "push eax" << endl;
                        }
                        os.pop(); // 弹出左括号
                    } else if (precedence.find(ch) != precedence.end()) {
                        while (!os.empty() && precedence[ch] <= precedence[os.top()] && os.top() != '(') {
                            char op = os.top();
                            os.pop();
                            int b = ns.top();
                            ns.pop();
                            int a = ns.top();
                            ns.pop();
                            ns.push(calculate(a, b, op)); // 计算并将结果入栈
                            cout << "push eax" << endl;
                        }
                        os.push(ch); // 当前操作符入栈
                    } else {
                        // 如果是数字
                        result = stoi(word);
                        flag1 = 1;
                        if (flag2) {
                            cout << "mov eax, " << result << endl;
                            cout << "push eax" << endl;
                        }
                        ns.push(result);
                    }
                }
            }
        }
    }
    // 关闭文件
    inputFile.close();

    return 0;
}