// boundary order traversal of a binary tree in anti-clockwise order

+++++++++++++++++++++++++++-------------------------------------------------------------------------------------

//logic
firstly add the root if it is not a leaf node
//then add all the left boundary nodes except root nodes
//then add all the leaf nodes
//then add all the right boundary nodes in reverse order

+++++++++------------------------------------------------------------------------------------------------------------------------------------------------------------

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

// check if node is a leaf node
bool isLeaf(node *root)
{
    if(!root->left && !root->right)
        return true;
    return false;
}

// add all the left boundary nodes
void addLeft(node *root, vector<int>&res)
{
    node *curr=root->left;
    while(curr)
    {
        if(!isLeaf(curr))
            res.push_back(curr->data);
        if(curr->left)
            curr=curr->left;
        else
            curr=curr->right;
    }
}

// add all the leaf nodes of the tree
void addLeaf(node *root, vector<int>&res)
{
    if(!root)
        return;
    if(isLeaf(root))
        res.push_back(root->data);
    addLeaf(root->left, res);
    addLeaf(root->right, res);
}


//add all the right boundary nodes and store it in reverse direction
void addRight(node *root, vector<int>&res)
{
    vector<int>v;
    node *curr=root->right;
    while(curr)
    {
        if(!isLeaf(curr))
            v.push_back(curr->data);
        if(curr->right)
            curr=curr->right;
        else
            curr=curr->left;
    }
    for(int i=v.size()-1; i>=0; --i)
    {
        res.push_back(v[i]);
    }
}

// boundary traversal of a binary tree in anticlockwise direction, i.e., (left boundary, all leaf nodes, right boundary in reverse order)
void BoundaryTraversal(node *root)
{
    if(!root)
        return;
    vector<int>res;
    if(!isLeaf(root))
        res.push_back(root->data);
    addLeft(root, res);
    addLeaf(root, res);
    addRight(root, res);
    for(auto x:res)cout<<x<<' ';
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
    BoundaryTraversal(root);
    return 0;
}
