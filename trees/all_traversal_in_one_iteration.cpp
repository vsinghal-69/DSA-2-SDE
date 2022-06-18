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

// recursive postorder traversal
void postorder(node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<' ';
    }
}

void oneTraversal(node *root)
{
    if(!root)
        return;
    vector<int>pre;// preorder traversal
    vector<int>in; // inorder traversal
    vector<int>post; // postorder traversal
    stack<pair<node *, int>>s;
    s.push({root, 1});
    while(!s.empty())
    {
        node *temp=s.top().first;
        int ct=s.top().second;
        if(ct==1)
        {
            pre.push_back(temp->data);
            s.top().second=2;
            if(temp->left)
                s.push({temp->left,1});
        }
        else if(ct==2)
        {
            in.push_back(temp->data);
            s.top().second=3;
            if(temp->right)
                s.push({temp->right, 1});
        }
        else
        {
            post.push_back(temp->data);
            s.pop();
        }
    }
    for(auto x:pre)cout<<x<<' ';
    cout<<'\n';
    for(auto x:in)cout<<x<<' ';
    cout<<'\n';
    for(auto x:post)cout<<x<<' ';
    cout<<'\n';
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
    oneTraversal(root);
    return 0;
}
