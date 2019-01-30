// string.find()
// 算符优先级!=高于=; *和.
// 注意边界值，尤其是首尾
// algorithm::swap()
// algorithm::transform
// algorithm::sort()是不稳定的

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct word {
    string s;
    int num;
};

bool cmp(word a, word b) {
    string c = a.s, d = b.s;
    transform(c.begin(),c.end(), c.begin(), ::toupper);
    transform(d.begin(), d.end(), d.begin(), ::toupper);
    if(c.length() > d.length()){
        swap(c, d);
        for(int i = 0; i < c.length(); i++) 
            if(c[i] != d[i])
                return c[i] > d[i];
        return false;
    } 
    else {
        for(int i = 0; i < c.length(); i++) 
            if(c[i] != d[i])
                return c[i] < d[i];
        if(c.length() == d.length())
            return a.num < b.num;
        return true;
    }
}

int main() {
    vector<word> words;
    string in;
    word w;
    int pos = 0, count = 0;
    getline(cin, in);
    while((pos = in.find(" ")) != string::npos) {
        w.s = in.substr(0, pos);
        w.num = count++;
        words.push_back(w);
        in = in.substr(pos + 1);
    }
    w.s = in.substr(0, pos);
    w.num = count++;
    words.push_back(w);
    sort(words.begin(), words.end(), cmp);    
    vector<word>::iterator i = words.begin();
    cout << (*i++).s;
    for( ;i != words.end(); i++) 
        cout << ' ' << (*i).s;       
}