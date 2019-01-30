// 传指针要提前分配空间，指针是传值不是传引用

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct node{
    node *lnode = NULL;
    node *rnode = NULL;
    char name;
};

void build(string post, string in, node *tree) {
    int i;
    string a, b;
    tree->name = post[post.length() - 1];
    for(i = 0; i < in.length(); i++)
        if(in[i] == post[post.length() - 1])
            break;
    if(i > 0) {
        tree->lnode = new node;
        build(post.substr(0, i), in.substr(0, i), tree->lnode);
    }
    if(i < post.length() - 1) {
        tree->rnode = new node;
        build(post.substr(i, post.length() - i - 1), in.substr(i + 1), tree->rnode);
    }
        
}

void preorder(node *tree) {
    if(tree == NULL)
        return;
    cout << tree->name;
    preorder(tree->lnode);
    preorder(tree->rnode);
}

int main() {
    string postorder, inorder;
    cin >> postorder >> inorder;
    node *tree = new node;
    build(postorder, inorder, tree);
    preorder(tree);
    return 0;
}