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

// recursive inorder traversal
void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<' ';
        inorder(root->right);
    }
}

// iterative inorder traversal
void ino(node *root)
{
    if(!root)
        return;
    stack<node *>s;
    s.push(root);

    while(!s.empty())
    {
        if(root)
        {
            root=root->left;
            if(root)
                s.push(root);
        }
        else{
            node *temp=s.top();
            s.pop();
            cout<<temp->data<<' ';
            root=temp->right;
            if(root)
            {
                s.push(root);
            }
        }
    }
}

int main()
{
    node *root=new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(6);
    root->left->right->right=new node(7);

    ino(root);


    return 0;
}
