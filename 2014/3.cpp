#include<iostream>
#include<string>
using namespace std;

int main() {
    int cur = 0, biggest = 0;
    string in;
    cin >> in;
    for(int i = 0; i < in.length(); i++) {
        if(in[i] == '(')
            cur + 1 > biggest ? biggest = ++cur : ++cur;
        else if(in[i] == ')')
            cur--;
    }
    cout << biggest << endl;
    return 0;
}