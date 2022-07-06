// optimised approach
//tc: o(n) 
//sc: o(n)

void solve(Node *root, int level, vector<int>&ans)
{
    if(root)
    {
       if(ans.size()==level)
       {
           ans.push_back(root->data);
       }
       solve(root->left, level+1, ans);
       solve(root->right, level+1, ans);
    }
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int>ans;
    solve(root, 0, ans);
    return ans;
}


=====================================================================================================================================

// optimised approach
//tc: o(n) 
//sc: o(n)

 void rightView(TreeNode *root, int level, vector<int>&ans)
    {
        if(!root)
            return;
        if(ans.size()==level)
            ans.push_back(root->val);
        rightView(root->right, level+1, ans);
        rightView(root->left, level+1, ans);
    }
    
   //Function to return a list containing elements of right view of the binary tree. 
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        rightView(root, 0, ans);
        return ans;
    }
