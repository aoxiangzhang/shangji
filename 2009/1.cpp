// 字符串操作,int转string，string转int，c++11不同？？？？？？
// stl

#include<iostream>
#include<string>
using namespace std;

int main() {
    string a[4];
    string name;
    int size = 0;
    while(cin >> name) {
        if(name == "#")
            break;
        if(size < 4)
            size++;
        for(int i = size - 1; i > 0; i--)
             a[i] = a[i - 1];
        a[0] = name;
        for(int i = 0; i < size; i++)
            cout << i+1 << "=" << a[i] << " ";
        cout << endl;
    }
}