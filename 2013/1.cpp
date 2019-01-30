#include<iostream>
using namespace std;

void find(int a, int b) {
    if(a % b == 0)
        cout << b << endl;
    else
        b > a % b ? find(b, a % b) : find(a % b, b);
}

int main() {
    int a, b;
    while(cin >> a >> b) {
        if(a > b)
            find(a, b);
        else 
            find(b, a);
    }
}