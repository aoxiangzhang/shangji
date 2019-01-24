#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

void split(string s, vector<int> v) {
    int flag = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ',') {
            v.push_back(stoi(s.substr(flag, i).c_str()));
            flag = ++i;
        }
    }
}

int main() {
    string str_data, str_group;
    vector<int> vec_data, vec_group;
    vector<map<int, int> > arr;
    int max_group = 0;
    cin >> str_data >> str_group;
    split(str_data, vec_data);
    split(str_group, vec_group);
    for(int i = 0; i < vec_group.size(); i++)
        if(max_group < vec_group[i]) {
            
        }

}