// 注意判断条件时的边界值，按规则办事！！！！！！！！！！！！！！！！！
// 注意输入格式，一行是getline不是cin>>in

#include<iostream>
#include<string>
using namespace std;

int main() {
    string in;
    int flag = 0, i = -1, read = 0, _num = 0, have = 0;
    getline(cin, in);
    while(++i < in.length()) {
        if(read == 0) {
            if(in[i] >= '0' && in[i] <= '9') {
                flag = i;
                read = 1;
                _num = 0;
                have = 0;
            }
            else if((in[i] == '+' || in[i] == '-') && in[i+1] >= '0' && in[i+1] <= '9') {
                have = 0;
                if(in[i] == '+')
                    have = 1;
                flag = i;
                read = 1;
                _num = 0;
            }
        }
        else {
            if((in[i] < '0' || in[i] > '9') && in[i] != '.' && in[i] != '+' && in[i] != '-') {
                read = 0;
                if(have == 1)
                    cout << '+';
                cout << stod(in.substr(flag, i - flag)) << ' ';
            }
            else if(in[i] == '.') { 
                if(in[i+1] < '0' && in[i+1] > '9') {
                    read = 0;
                    if(have == 1)
                        cout << '+';
                    cout << stod(in.substr(flag, i - flag)) << ' ';
                }
                else if(_num == 0) {
                    _num++;
                }
                else if(_num == 1) {
                    read = 0;
                    if(have == 1)
                        cout << '+';
                    cout << stod(in.substr(flag, i - flag)) << ' ';
                }
            }
            else if(in[i] == '+' || in[i] == '-') {
                read = 0;
                if(have == 1)
                    cout << '+';
                cout << stod(in.substr(flag, i - flag)) << ' ';
                i--;
            }
        }
    }
    if(have == 1)
        cout << '+';
    cout << stod(in.substr(flag, i - flag));
}