// 表达式树和前缀中缀后缀表达式关系
// 表达式树法

#include<iostream>
#include<string>
#include<map>
using namespace std;

map<char, int> prioArr;

struct node {
    node *lnode = NULL;
    node *rnode = NULL;
    node *parant = NULL;
    char data;
    int priority = 0;
};

void initPrio() {
    prioArr['+'] = 1; prioArr['-'] = 1; prioArr['*'] = 2; prioArr['/'] = 2; prioArr['('] = 2; prioArr[')'] = -2;
}

void out(node *tree) {
    if(tree == NULL) 
        return;
    cout << tree->data;
    out(tree->lnode);
    out(tree->rnode);
}

int main() {
    string in;
    int prio_now = 0, i = 0;
    node *tree = new node;
    node *curr = tree;
    tree->priority = -1;
    initPrio();
    cin >> in;
    while(i < in.length()) {
        if(in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/')
            if(prioArr[in[i]] + prio_now > curr->priority) {
                node *newNode = new node;
                newNode->data = in[i];
                newNode->priority = prioArr[in[i]] + prio_now;
                newNode->parant = curr;
                newNode->lnode = curr->rnode;
                curr->rnode->parant = newNode;
                curr->rnode = newNode;
                curr = curr->rnode;
            }
            else {
                while(prioArr[in[i]] + prio_now <= curr->priority)
                    curr = curr->parant;
                node *newNode = new node;
                newNode->data = in[i];
                newNode->priority = prioArr[in[i]] + prio_now;
                newNode->parant = curr;
                newNode->lnode = curr->rnode;
                curr->rnode->parant = newNode;
                curr->rnode = newNode;
                curr = curr->rnode;
            }
        else if(in[i] == '(' || in[i] == ')')
            prio_now += prioArr[in[i]];
        else {
            curr->rnode = new node;
            curr->rnode->data = in[i];
            curr->rnode->parant = curr;
        }  
        i++;
    }
    out(tree->rnode);
}