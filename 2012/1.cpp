// 逻辑要清楚，思路要明确

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int ints[10];
    int i = 0;
    while(cin >> ints[i] && i++ < 9);
    sort(ints, ints + 10);
    i = 0;
    cout << ints[i++];
    while(i < 10)
        cout << "," << ints[i++];
    return 0;
}