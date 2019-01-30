// 格式？c风格输入输出

#include<iostream>
using namespace std;

int main() {
    int recent[3];
    int num = 0;
    int in, flag = 0;
    while(cin >> in) {
       for(int i = 0; i < num; i++)
           if(recent[i] == in) {
               flag = 1;
               break;
           }
        if(flag == 1)
            flag = 0;
        else {
            recent[2] = recent[1];
            recent[1] = recent[0];
            recent[0] = in;
            num < 3 ? num++ : num = 3;
        }
        cout << recent[0];
        for(int i = 1; i < num; i++)
            cout << ',' << recent[i];
        cout << endl;
    }
}