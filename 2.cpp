#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string>
using namespace std;

class c {
    public:
    int d;
};

void a(c*b) {
    (*b).d = 2;
}

int main() {
    c e;
    e.d = 1;
    a(&e);
    cout << e.d;
}