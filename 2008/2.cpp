#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    string name, path, neirong;
    cin >> name >> path;
    getline(cin, neirong);
    ofstream a((path+name).c_str());
    if(a) {
        while(1) {
            getline(cin, neirong);
            if(neirong == "#")
                break;
            else 
                a << neirong << endl;
        }
    }
    a.close();
    cout << path << endl;
    cout << name << endl;
    ifstream b((path + name).c_str());
    if(b)
        while(getline(b, neirong))
            cout << neirong << endl;
    b.close();
    return 0;
}