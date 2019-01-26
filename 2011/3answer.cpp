// 逻辑要完整，按规则办事

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct person {
    string name;
    int father;
};

int main() {
    string relationship, target;
    vector<person> persons;
    person p;
    stack<int> sta;
    cin >> relationship;
    cin >> target;
    int i = 1, flag = 1;
    sta.push(-1);
    while(i < relationship.size()) {
        if(relationship[i] == '(') {
            p.name = relationship.substr(flag, i - flag);
            p.father = sta.top();
            persons.push_back(p);
            sta.push(persons.size() - 1);
            flag = ++i;
        }
        else if(relationship[i] == ',') {
            if(i - flag > 0) {
                p.name = relationship.substr(flag, i - flag);
                p.father = sta.top();
                persons.push_back(p);
            }
            flag = ++i;
        }
        else if(relationship[i] == ')') {
            if(i - flag > 0) {
                p.name = relationship.substr(flag, i - flag);
                p.father = sta.top();
                persons.push_back(p);
            }
            sta.pop();
            flag = ++i;
        }
        else
            i++;
    }
    stack<string> list;
    list.push(target);
    int pos;
    for(int i = 0; i < persons.size(); i++) {
        if(persons[i].name == target) {
            pos = persons[i].father;
            break;
        }  
    }  
    while(pos >= 0) {
        list.push(persons[pos].name);
        pos = persons[pos].father;
    }
    cout << list.top();
    list.pop();
    while(!list.empty()) {
        cout << "->" << list.top();
        list.pop();
    }
    return 0;
}