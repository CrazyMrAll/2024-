#include <iostream>
using namespace std;

struct Student
{
    char name[10];
    int score;
};

int main()
{
    int n;
    cin >> n;
    // Student *student = new Student[n]; 为什么有问题。。。。。
    Student student[n];
    for ( int i=0; i<n; i++ ) {
        int j = 0;
        cin.ignore(1024, '\n');
        while ( cin.get(student[i].name[j]) ) {
            if ( student[i].name[j]==',' ) {
                student[i].name[j] = '\0';
                break;
            }
            j++;
        }
        cin >> student[i].score;
    }
    for ( int i=0; i<n-1; i++ ) {
        for ( int j=0; j<n-i; j++ ) {
            if ( student[j].score < student[j+1].score) {
                Student tmp = student[j];
                student[j] = student[j+1];
                student[j+1] = tmp;
            }
        }
    }
    for ( int i=0; i<n; i++ ) {
        cout << student[i].name << "," << student[i].score << endl;
    }
    return 0;
}