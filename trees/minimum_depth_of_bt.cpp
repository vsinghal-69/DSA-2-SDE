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

// minimum depth of a binary tree from root to nearest leaf path
int minDepth(node* root) {
        if(!root)
            return 0;
        if(root->left && root->right)
        {
            return min(minDepth(root->left), minDepth(root->right))+1;
        }
        else if(root->left)
        {
            return minDepth(root->left)+1;
        }
        return minDepth(root->right)+1;
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
    cout<<minDepth(root);
    return 0;
}
