#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string data[100];
    int n = 0;
    while(cin >> data[n++]);
    n--;
    sort(data, data + n);
    char now = data[0][0];
    int count = 1;
    for(int i = 1; i < n; i++) {
        if(data[i][0] == now)
            count++;
        else {
            cout << now << ',' << count << endl;
            now = data[i][0];
            count = 1;
        }
    }
    cout << now << ',' << count << endl;
    return 0;
}