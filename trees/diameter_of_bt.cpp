/* Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them. */

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


//brute force solution
//tc: o(n*n)  traversing every node and finding left and right subtree height for every node
//sc: o(n)  stack memory equal to max height(n) by recursive calls

class Solution {
public:
    int height(TreeNode *root)
    {
        if(!root)
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return max(lh, rh)+1;
    }
    
    int diameter(TreeNode* root, int &maxm)
    {
        if(!root)
            return 0;
        int lsh=height(root->left);
        int rsh=height(root->right);
        maxm=max(maxm, lsh+rsh);
        diameter(root->left, maxm);
        diameter(root->right, maxm);
        return maxm;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxm=0;
        return diameter(root, maxm);
    }
};


//optimised solution
//tc: o(n) as we traverse only each node like in case of finding max depth of a bt
//sc: o(n) stack memory by recursive function calls
class Solution {
public:
    int diameter(TreeNode *root, int &maxm)
    {
        if(!root)
            return 0;
        int lsh=diameter(root->left, maxm);
        int rsh=diameter(root->right, maxm);
        maxm= max(maxm, lsh+rsh);
        return max(lsh, rsh)+1;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxm=0;
        diameter(root, maxm);
        return maxm;
    }
};