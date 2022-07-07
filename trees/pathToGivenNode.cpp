// problem link : https://www.interviewbit.com/problems/path-to-given-node/

/* Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.

NOTE:

No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists.*/

==============================================================================================

//optimised solution
//tc: O(n)
//sc: O(n)

bool rootToNode(TreeNode *root, int b, vector<int>&ans)
{
    if(!root)
        return 0;
    ans.push_back(root->val);
    if(root->val==b || (rootToNode(root->left, b, ans) || rootToNode(root->right, b, ans)))
        return 1;
    ans.pop_back();
    return 0;
} 
 

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    if(!A)
        return ans;
    rootToNode(A, B, ans);
    return ans;
}