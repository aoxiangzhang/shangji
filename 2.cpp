#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string>
using namespace std;

struct c {
    int d;
};

void a(c *b) {
    b->d = 2;
    b = NULL;
}

int main() {

    set<int, int> h;
    h.insert(1,1);
    h.insert(1,2);
    h.insert(2,2);
    for(set<int, int>::iterator i = h.begin(); i != h.end(); i++) {
        cout << *i << endl;
    }
    // map<c, c> g;
    // c f[3];
    // c *e = new c;
    // e->d = 1;
    // a(e);
    // cout << e->d;
}