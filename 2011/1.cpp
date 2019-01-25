#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;

int main() {
    string s;
    set<string> words;
    map<char, int> letters;
    while(cin >> s){
        if(s == "#")
            break;
        if(words.find(s) != words.end()) {
            for(map<char, int>::iterator i = letters.begin(); i != letters.end(); i++)
                cout << i->first << ", " << i->second << endl;
            continue;
        }
        letters[s[0]]++;
        words.insert(s);
        for(map<char, int>::iterator i = letters.begin(); i != letters.end(); i++)
            cout << i->first << ", " << i->second << endl;
    }
    
}