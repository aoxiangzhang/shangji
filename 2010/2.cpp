// substr第二个参数是长度。不是结尾下标
// stl
// 思路不等于代码

#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;

map<char, double> isp;
map<char, double> osp;

void intopost(string s, queue<string>& post) {
    stack<char> operators;
    operators.push('#');
    int flag = 0;
    for(double i = 0; i < s.size();) {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')') {
            if(i - flag > 0)
                post.push(s.substr(flag, i - flag));
            if(isp[s[i]] > osp[operators.top()]) {
                operators.push(s[i++]);
            }
            else if(isp[s[i]] < osp[operators.top()]) {
                string s;
                s.push_back(operators.top());
                post.push(s);
                operators.pop();
            }
            else {
                operators.pop();
                i++;
            }
            flag = i;
        }
        else
            i++;
    }
    if(flag < s.size())
        post.push(s.substr(flag));
    while(operators.top() != '#') {
        string s;
        s.push_back(operators.top());
        post.push(s);
        operators.pop();
    }
}

void initOperator() {
    isp [')'] = 1; isp['+'] = isp['-'] = 2; isp['*'] = isp['/'] = 4; isp['('] = 6;
    osp ['#'] = 0; osp ['('] = 1; osp['+'] = osp['-'] = 3; osp['*'] = osp['/'] = 5; osp[')'] = 6;
}

double postCal(queue<string>& post, stack<double>& num) {
    while(!post.empty()) {
        if(post.front() == "+" || post.front() == "-" || post.front() == "*" || post.front() == "/") {
            double a = num.top();
            num.pop();
            double b = num.top();
            num.pop();
            switch(post.front()[0]) {
                case '+':
                    num.push(a + b);
                    break;
                case '-':
                    num.push(a - b);
                    break;
                case '*':
                    num.push(a * b);
                    break;
                case '/':
                    num.push(a / b);
                default:
                    break;
            }
        }
        else {
            // cout << "is empty" << post.empty() << "push num" << post.front();
            num.push(stod(post.front()));
            
        }
        post.pop();
    }
    return num.top();
}

int main() {
    string s;
    queue<string> post;
    stack<double> num;
    initOperator();
    cin >> s;
    intopost(s, post);
    // while(!post.empty()) {
    //     cout << post.front() << '|';
    //     post.pop();
    // }
    
    cout << postCal(post, num);
    return 0;
}