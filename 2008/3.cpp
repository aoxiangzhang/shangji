// �׳��������쳣
// vectorʹ��

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
            cout << "�����뱻�����������";
            cin >> a >> b;
            if(b == 0)
                throw A();
            cout << "���쳣�����Ϊ��" << a / b << endl;

            int n, data;
            cout << "�������鳤�ȣ�";
            cin >> n;
            cout << "����������ֵ��int������-100������";
            while(cin >> data) {
                if(data == -100)
                    break;
                v.push_back(data);
            }
            if(v.size() > n)
                throw B();
            cout << "���쳣���ո���������飺";
            for(it = v.begin(); it != v.end(); it++)
                cout << *it << " ";
            cout << endl;
            v.clear();
        }catch(A){
            cout << "0��������" << endl;
        }catch(B){
            v.clear();
            cout << "����Խ�磡" << endl;
        }
    }
    return 0;
}