#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<string> words;
    string word;
    while(cin >> word)
        words.push_back(word);
    sort(words.begin(), words.end());
    vector<string>::iterator i = words.begin();
    cout << *i++;
    for(; i != words.end(); i++) 
        cout << " " << *i;
    return 0;
}