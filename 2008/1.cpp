// algorithm��׼��
// string��

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string name;
    vector<string>::iterator i;
    vector<string> names;
    while(1) {
        cout << "������������";
        cin >> name;
        while(name != "#") {
            names.push_back(name);
            cin >> name;
        }
        sort(names.begin(), names.end());
        for(i = names.begin(); i != names.end(); i++)
            cout << *i << endl;
    }
}