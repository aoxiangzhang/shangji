#include<iostream>
using namespace std;

float cal(double H, int n) {
    if(n == 1)
        return 0;
    else
        return H + cal(H / 2, n - 1);
}

int main()
{
    double H;
    int n;
    cin >> H >> n;
    
    cout << "res" << endl;
    cout << H + cal(H, n);
    return 0;
}
