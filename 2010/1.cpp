// \是转义字符，要用两个
// 使用-std=c++11 用c++11标准编译
// switch语句中不能定义变量
// vector使用erase删除元素后，iterator指针变成野指针，无法继续循环，应获取erase（）返回值为下一个指针代码见下

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    vector<int> ints;
    string in;
    int a, b;
    while(getline(cin, in)){
        if(in == "#")
            break;
        switch(in[0]) {
            case 'a':
                ints.push_back(stoi(in.substr(2)));
                break;
            case 'c':
                for(int i = 2; i < in.size(); i++)
                    if(in[i] == '\\') {
                        a = stoi(in.substr(2, i));
                        b = stoi(in.substr(i + 1));
                        break;
                    }
                for(vector<int>::iterator i = ints.begin(); i != ints.end(); i++)
                    if(*i == a)
                        *i = b;
                break;
            case 'd':
                a = stoi(in.substr(2));
                for(vector<int>::iterator i = ints.begin(); i != ints.end();)
                    if(*i == a)
                        i = ints.erase(i);
                    else
                        i++;
                break;
            case 's':
                sort(ints.begin(), ints.end());
                break;
            default:
                break;
        }
        for(vector<int>::iterator i = ints.begin(); i != ints.end(); i++)
            cout << *i << ' ';
        cout << endl;
    }
}