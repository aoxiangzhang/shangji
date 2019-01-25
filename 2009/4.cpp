#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

string a;
vector<string> words;
typedef pair<string, int> c;

bool cmp(c a, c b){
    return a.second > b.second;
}

void split() {
   int flag = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == ' ') {
            words.push_back(a.substr(flag, i - flag));
            flag = i + 1;
        }
        else if(a[i] == ',') {
            words.push_back(a.substr(flag, i++ - flag));
            flag = i + 1;
        }
        else if(a[i] == '.') {
            words.push_back(a.substr(flag, i++ - flag));
            flag = i + 1;
        }
    }
}

int main() {
    map<string, int> b;
    getline(cin, a);
    split();
    for(vector<string>::iterator v = words.begin(); v != words.end(); v++) {
        b[*v]++;
    }
    vector<c> words_vec(b.begin(), b.end());
   
    sort(words_vec.begin(), words_vec.end(), cmp);
    for(vector<c>::iterator v = words_vec.begin(); v != words_vec.end(); v++) {
        cout << v->first << " " << v->second << endl;
    }
    return 0;
}