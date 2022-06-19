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

int height(node * root)
{
    if(!root)
        return 0;

    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh, rh)+1;

    // return max(height(root->left), height(root->right))+1;
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
    cout<<height(root);
    return 0;
}
