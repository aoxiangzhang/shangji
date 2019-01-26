// 这也太麻烦了吧，分析需要的信息，只保留需要的，见答案

#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

struct tree {
    tree *brotherNode = NULL;
    tree *chileNode = NULL;
    string name;
};

int main() {
    tree *relationtree = new tree;
    tree *curr = relationtree;
    stack<tree *> nodeStack;
    vector<tree *> nodeVec;
    string relationship, target;
    int flag = 1, i = 1;
    cout << "input relationship: ";
    cin >> relationship;
    nodeStack.push(curr);
    while(!nodeStack.empty())
        for(; i < relationship.size();)
            if(relationship[i] == '(') {
                nodeStack.push(curr);
                curr->name = relationship.substr(flag, i - flag);
                curr->chileNode = new tree;
                curr = curr->chileNode;
                flag = ++i;
            }
            else if(relationship[i] == ',') {
                if(curr->name.empty())
                    curr->name = relationship.substr(flag, i - flag);
                curr->brotherNode = new tree;
                curr = curr->brotherNode;
                flag = ++i;
            }
            else if(relationship[i] == ')') {
                if(curr->name.empty())
                    curr->name = relationship.substr(flag, i - flag);
                curr = nodeStack.top();
                nodeStack.pop();
                flag = ++i;
            }
            else
                i++;

    cout << "input target: ";
    cin >> target;
    flag = 0;
    while(1)
        if(relationtree->name == target) {
            nodeVec.push_back(relationtree);
            break;
        }
        else if(relationtree->chileNode != NULL && flag == 0) {
            nodeVec.push_back(relationtree);
            relationtree = relationtree->chileNode;
        }
        else if(relationtree->brotherNode != NULL) {
            relationtree = relationtree->brotherNode;
            flag = 0;
        }
        else if(!nodeVec.empty()){
            relationtree = *(nodeVec.begin() + nodeVec.size() - 1);
            nodeVec.pop_back();
            flag = 1;
        }
        else
            break;
    
    cout << nodeVec[0]->name;
    for(int i =1; i < nodeVec.size(); i++)
        cout << "->" << nodeVec[i]->name;
        
    return 0;
}