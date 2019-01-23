// 抛出、接受异常
// vector使用

#include<iostream>
#include<vector>
using namespace std;

class A {};
class B {};

int main() {
    vector<int> v;
    vector<int>::iterator it;
    while(1) {
        try {
            double a, b;
            cout << "请输入被除数与除数：";
            cin >> a >> b;
            if(b == 0)
                throw A();
            cout << "无异常，结果为：" << a / b << endl;

            int n, data;
            cout << "输入数组长度：";
            cin >> n;
            cout << "输入数组数值（int），以-100结束：";
            while(cin >> data) {
                if(data == -100)
                    break;
                v.push_back(data);
            }
            if(v.size() > n)
                throw B();
            cout << "无异常，刚刚输入的数组：";
            for(it = v.begin(); it != v.end(); it++)
                cout << *it << " ";
            cout << endl;
            v.clear();
        }catch(A){
            cout << "0做除数！" << endl;
        }catch(B){
            v.clear();
            cout << "数组越界！" << endl;
        }
    }
    return 0;
}