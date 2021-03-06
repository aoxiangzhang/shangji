// pair定义使用
// 对map的value进行排序需要转化成vector
// 审题注意输入格式
// find()函数用法，未查询到结果返回int型string::npos

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

struct student {
    vector<double> grades;
    int average = 0;
    int failed = 0;
};

typedef pair<string, student> p;

bool cmp(p a, p b) {
    return a.second.failed > b.second.failed;
}

int main() {
    map<string, student> students;
    string in;
    while(getline(cin, in)) {
        int flag = in.find(' ');
        student &s = students[in.substr(0, flag)];
        in = in.substr(flag + 1);
        while(in.find(' ') != string::npos) {
            flag = in.find(' ');
            s.grades.push_back(stod(in.substr(flag + 1)));
            s.average = (s.average * (s.grades.size() - 1) + stod(in.substr(flag + 1))) / s.grades.size();
            if(stod(in.substr(flag + 1)) < 60)
                s.failed++;
            in = in.substr(flag + 1);
        }
        s.grades.push_back(stod(in));
        s.average = (s.average * (s.grades.size() - 1) + stod(in)) / s.grades.size();
        if(stod(in) < 60)
            s.failed++;
        vector<p> ss(students.begin(), students.end());
        sort(ss.begin(), ss.end(), cmp);
        vector<p>::iterator i = ss.begin();
        cout << i->first << ' ' << i->second.average << endl;
        i++;
        for(; i != ss.end(); i++)
            cout << i->first << ' ' << i->second.average << endl;
    }

}