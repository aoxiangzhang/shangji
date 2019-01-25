// 数据读写方式？？？？？？？？？
// 注意map的key为实际值，数组vector下标从0开始
// 注意边界值，如输入的最后一个没有逗号
// 熟练使用stl与数组，灵活使用合适的数据结构

#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;

void split(string s, vector<int>& v) {
    int flag = 0;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == ',') {
            v.push_back(atoi(s.substr(flag, i).c_str()));
            flag = ++i;
        }
    v.push_back(atoi(s.substr(flag).c_str()));
}

int main() {
    string str_data, str_group;
    vector<int> vec_data, vec_group;
    map<int, int> one_group;
    map<int, int> *arr;
    int max_group = 0;
    cin >> str_data >> str_group;
    split(str_data, vec_data);
    split(str_group, vec_group);
    for(int i = 0; i < vec_group.size(); i++) {
        if(max_group < vec_group[i]) 
            max_group = vec_group[i];
        one_group[vec_data[i]] = 0;
    }
    arr = new map<int, int>[max_group];
    for(int i = 0; i < max_group; i++)
        arr[i] = one_group;
    for(int i = 0; i < vec_group.size(); i++) 
        arr[vec_group[i] - 1][vec_data[i]]++;
    for(int i = 0; i < max_group; i++) {
        cout << i + 1 << "={"; 
        map<int, int>::iterator j = arr[i].begin();
        cout << j->first << '=' << j->second;
        j++;
        for(; j != arr[i].end(); j++)
            cout << ", " << j->first << '=' << j->second;
        cout << '}' << endl;
    }
}