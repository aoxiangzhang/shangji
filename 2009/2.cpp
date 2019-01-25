// ÎÄ¼ş¶ÁĞ´
// ÉóÌâ

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    string a[4];
    string name;
    int size = 0;
    ofstream out("Name.txt");
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
    for(int i = 0; i < size; i++)
        out << i+1 << "=" << a[i] << " ";
    out.close();
}