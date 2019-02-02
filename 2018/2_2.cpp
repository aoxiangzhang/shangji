#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

typedef pair<int, int> p;
set<int> primes;
vector<p> primesResult[51];
map<int, int> result;

bool cmp(p a, p b) {
    return (a.second) > (b.second);
}

void initPrims(int b) {
    for(int i = 2; i < b; i++) {
        bool flag = 1;
        for(int j = 2; j <= sqrt(i); j++)
            if(i % j == 0) {    
                flag = 0;
                break;
            }
        if(flag)
            primes.insert(i);
    }
}

bool judge(int a) {
    for(set<int>::iterator i = primes.begin(); i != primes.end(); i++)
        if(*i == a)
            return 1;
    return false;
}

int main() {
    int a, b;
    map<int, int> out;
    cin >> a >> b;
    initPrims(b);
    for(int i = a % 2 == 0 ? a : a + 1; i <= b; i += 2) {
        for(set<int>::iterator iter = primes.begin(); *iter <= i / 2; iter++) {
            if(judge(i - *iter)) {
                primesResult[i].push_back(p(*iter, i - *iter));
                out[i]++;
            }
        }
    }
    bool flag = 1;
    map<int, int> out1 = out;
    while(flag) {
        for(int i = a % 2 == 0 ? a : a + 1; i <= b; i += 2) {
            result[primesResult[i][out[i] - 1].first]++;
            result[primesResult[i][out[i] - 1].second]++;
        }
        vector<p> z(result.begin(), result.end());
        sort(z.begin(), z.end(), cmp);
        for(vector<p>::iterator i = z.begin(); i != z.end(); i++)
            cout << (*i).first << ' ' << (*i).second << ' ';
        cout << endl;
        result.clear();
        z.clear();
        for(map<int, int>::iterator i = out.begin(); ; i++) {
            if(i == out.end()) {
                flag = 0;
                break;
            }
            if((*i).second > 1) {
                (*i).second--;
                break;
            }
            else
                (*i).second = out1[(*i).first];
        }
    }
}