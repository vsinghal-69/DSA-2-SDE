#include<bits/stdc++.h>
using namespace std;


struct node
{
    node *left;
    node *right;
    int data;
    node(int x)
    {
        data=x;
        left=right=NULL;
    }
};

// recursive preorder traversal
void preorder(node *root)
{
    if(root)
    {
        cout<<root->data<<' ';
        preorder(root->left);
        preorder(root->right);
    }
}


// iterative preorder traversal using 1 stack

void pre(node *root)
{
    if(!root)
        return;
    stack<node *>s;
    s.push(root);
    while(!s.empty())
    {
        node *t=s.top();
        s.pop();
        cout<<t->data<<' ';
        if(t->right)
            s.push(t->right);
        if(t->left)
            s.push(t->left);
    }

}

int main()
{
    node *root=new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->left->right=new node(7);
    root->right->left->right->right=new node(8);
    preorder(root);
    cout<<".............\n";
    pre(root);

    return 0;
}
