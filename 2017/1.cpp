// char型为ASCII编码， char型1强制转为int型不是1，要(int)('1' - '0')
// 了解ASCII码

#include<iostream>
#include<string>
using namespace std;

int W[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char xtoy[11] = {'1', '0', 'x', '9', '8', '7', '6', '5', '4', '3', '2'};

int main() {
    string in;
    int sum = 0;
    cin >> in;
    for(int i = 0; i < 17; i++)
        // sum += stoi(in.substr(i, 1)) * W[i];
        sum += (int)(in[i] - '0') * W[i];
    xtoy[sum % 11] == in[17] ? cout << in << " 正确" << endl : cout << in << " 不正确" << endl;
}