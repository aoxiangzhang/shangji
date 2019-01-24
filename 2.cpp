#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> a;
    for(int i = 0; i < 5; i++)
        a.push_back(i);
    a.erase(a.begin() + 2);
    for(int i = 0; i < 4; i++)
        cout << a[i] << " ";
}