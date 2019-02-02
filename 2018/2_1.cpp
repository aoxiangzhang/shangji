#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> p;
vector<int> primes;
map<int, int> result;

bool cmp(p a, p b) {
    return (a.second) > (b.second);
}

bool judge(int a) {
    for(int j = 0; j < primes.size(); j++) 
        if(primes[j] == a)
            return true;
    return false;
}

void initPrimes() {
    for(int i = 2; i < 50; i++) {
        bool flag = true;
        for(int j = 2; j <= sqrt(i); j++)
            if(i % j == 0) {
                flag = false;
                break;
            }
        if(flag) 
            primes.push_back(i);
    }
}

int main() {
    int a, b;
    int arr[51][10][2] = {0};
    map<int, int> c;
    cin >> a >> b;
    initPrimes();
    for(int i = a % 2 == 0 ? a : a+1; i <= b; i += 2) {
        int count = 0;
        for(int j = 0; primes[j] <= i / 2; j++)
            if(judge(i - primes[j])) {
                arr[i][count][0] = primes[j];
                arr[i][count++][1] = i - primes[j];
                c[i]++;
            }
        c[i] = 0;
    }
    bool flag = 1;
    bool first = 1;
    while(1) {
        for(int i = a % 2 == 0 ? a : a+1; i <= b; i += 2) {
            result[arr[i][c[i]][0]]++;
            result[arr[i][c[i]][1]]++;
            if((i == a || i == a+1) && !first) 
                for(map<int, int>::iterator iter = c.begin(); ; iter++)
                    if(iter == c.end()) {
                        flag = 0;
                        break;
                    }
                    else if(arr[(*iter).first][(*iter).second + 1][0] != 0) {
                        (*iter).second++;
                        for(map<int, int>::iterator iter1 = c.begin(); iter1 != iter; iter1++)
                            (*iter1).second = 0;
                        break;
                    }
            else if(first)
                first = 0;
        }
        if(!flag)
            break;
        vector<p> v(result.begin(), result.end());
        sort(v.begin(), v.end(), cmp);
        for(int i = 0; i < v.size(); i++) 
            cout << v[i].first << ' ' << v[i].second << ' ';
        cout << endl;
        result.clear();
        v.clear();
    }
}