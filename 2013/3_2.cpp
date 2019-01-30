// Ñ¹Õ»·¨

#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;

map<char, int> isp;
map<char, int> osp;

void intopre(string s, stack<char>& post) {
    stack<char> operators;
    operators.push('#');
    int flag = 0;
    for(int i = s.length() - 1; i >= 0;) {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')') {
            if(isp[s[i]] > osp[operators.top()]) {
                operators.push(s[i--]);
            }
            else if(isp[s[i]] < osp[operators.top()]) {
                post.push(operators.top());
                operators.pop();
            }
            else {
                operators.pop();
                i--;
            }
            flag = i;
        }
        else {
            post.push(s[i]);
            i--;
        }
            
    }
    if(flag != 0)
        post.push(s[0]);
    while(operators.top() != '#') {
        post.push(operators.top());
        operators.pop();
    }
}

void initOperator() {
    isp [')'] = 6; isp['+'] = isp['-'] = 3; isp['*'] = isp['/'] = 4; isp['('] = 1;
    osp ['#'] = 0; osp ['('] = 6; osp['+'] = osp['-'] = 2; osp['*'] = osp['/'] = 5; osp[')'] = 1;
}


int main() {
    string s;
    stack<char> post;
    initOperator();
    cin >> s;
    intopre(s, post);
    while(!post.empty()) {
        cout << post.top();
        post.pop();
    }
    return 0;
}