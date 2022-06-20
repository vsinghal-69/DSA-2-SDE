/* A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//optimised solution
//tc: o(n)
//sc: o(n)

class Solution {
public:
    int pathSum(TreeNode *root, int &maxm)
    {
        if(!root)
            return 0;
        int lss=max(0, pathSum(root->left, maxm));// if lss gives -ve val then return 0 
        int rss=max(0, pathSum(root->right, maxm));
        maxm=max(maxm, lss+rss+root->val);
        return root->val+max(lss, rss);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxm=INT_MIN;
        pathSum(root, maxm);
        return maxm;
    }
};