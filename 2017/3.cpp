// 按规则办事儿

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct student {
    string name;
    int grades[3];
    int average;
    int failed = 0;
};

bool cmp (student a, student b) {
    return (a.average) > (b.average);
}

int main() {
    int num;
    vector<student> students;
    student s;
    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> s.name >> s.grades[0] >> s.grades[1] >> s.grades[2];
        s.average = (s.grades[0] + s.grades[1] + s.grades[2]) / 3;
        if(s.grades[0] < 60 || s.grades[1] < 60 || s.grades[2] < 60)
            s.failed = 1;
        students.push_back(s);
        s.failed = 0;
    }
    for(vector<student>::iterator i = students.begin(); i != students.end(); i++)
        if((*i).failed == 1)
            cout << "*name:" << (*i).name << " score:" <<  (*i).grades[0] << ' ' << (*i).grades[1] << ' ' << (*i).grades[2] << endl;
    sort(students.begin(), students.end(), cmp);
    for(int i = 0; i < num; i++)
        cout << '[' << i << "] name:" << students[i].name << " " <<  students[i].grades[0] << ' ' << students[i].grades[1] << ' ' << students[i].grades[2] << endl;
}
