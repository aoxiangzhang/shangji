#include<iostream>
using namespace std;

int main() {
    int recent[3];
    int num = 0;
    int in, flag = 0;
    while(cin >> in) {
        for(int i = 0; i < num; i++)
            if(recent[i] == in) {
                if(i == 1)
                    swap(recent[0], recent[1]);
                else if(i == 2) {
                    swap(recent[0], recent[2]);
                    swap(recent[1], recent[2]);
                }
                flag = 1;
                break;
           }
        if(flag == 1)
            flag = 0;
        else {
            recent[2] = recent[1];
            recent[1] = recent[0];
            recent[0] = in;
            num < 3 ? num++ : num = 3;
        }
        cout << recent[0];
        for(int i = 1; i < num; i++)
            cout << ',' << recent[i];
        cout << endl;
    }
}