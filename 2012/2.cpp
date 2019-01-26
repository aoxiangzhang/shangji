// sort对class struct 进行排序需要重载比较函数

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct student {
    int id;
    string name;
    char gender;
    int age;
};

int ids[3] = {10, 20, 30};
string names[3] = {"wes", "ert", "str"};
char genders[3] = {'f', 'f', 't'};
int ages[3] = {23, 45, 89};

bool cmp(student s1, student s2) {
    return s1.id < s2.id;
}

int main() {
    vector<student> students;
    student s;
    string in;
    for(int i = 0; i < 3; i++) {
        s.id = ids[i];
        s.name = names[i];
        s.gender = genders[i];
        s.age = ages[i];
        students.push_back(s);
    }
    while(cin >> in) {
        int i =1, flag = 0;
        int z[3] = {0};
        if(in[0] == 'I') {
            for(; i < in.length(); i++)
                if(in[i] == ',')
                    z[flag++] = i;
            s.id = stoi(in.substr(1, z[0] - 1));
            s.name = in.substr(z[0] + 1, z[1] - z[0] - 1);
            s.gender = in[z[1] + 1];
            s.age = stoi(in.substr(z[2] + 1));
            students.push_back(s);
        }
        else {
            s.id = stoi(in.substr(1));
            for(vector<student>::iterator j = students.begin(); j != students.end(); j++)
                if(j->id == s.id) {
                    students.erase(j);
                    break;
                }
        }
        sort(students.begin(), students.end(), cmp);
        vector<student>::iterator j = students.begin();
        cout << "(" << j->id << "," << j->name << "," << j->gender << "," << j->age << ")";
        for(j++; j != students.end(); j++)
            cout << ",(" << j->id << "," << j->name << "," << j->gender << "," << j->age << ")";
        cout << endl;
    }
    return 0;
}