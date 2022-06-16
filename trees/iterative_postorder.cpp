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

// iterative postorder traversal using 2 stack
void post(node *root)
{
    if(!root)
        return;
    stack<node *>s;
    s.push(root);
    stack<int>ans;

    while(!s.empty())
    {
        node *t=s.top();
        s.pop();
        ans.push(t->data);
        if(t->left)
            s.push(t->left);
        if(t->right)
            s.push(t->right);
    }
    while(!ans.empty())
    {
        cout<<ans.top()<<' ';
        ans.pop();
    }
}

// iterative postorder traversal using 1 stack
// cram this solution, as it is not intuitive
void post1(node *root)
{
    if(!root)
        return;
    stack<node *>s;
    node *curr=root;
    while(curr || !s.empty())
    {
        if(curr)
        {
            s.push(curr);
            curr=curr->left;
        }
        else
        {
            node *temp=s.top()->right;
            if(temp)
            {
                curr=temp;
            }
            else
            {
                temp=s.top();
                s.pop();
                cout<<temp->data<<' ';
                while(!s.empty() && s.top()->right==temp)
                {
                    temp=s.top();
                    s.pop();
                    cout<<temp->data<<' ';
                }
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
    root->right->left=new node(6);
    root->right->left->right=new node(7);
    root->right->left->right->right=new node(8);
    postorder(root);
    cout<<".............\n";
    post1(root);

    return 0;
}
