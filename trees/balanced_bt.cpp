/* Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.*/

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


// brute force solution
//tc : o(n*n) n for every node and n for calculating height of every node
//sc : o(n), height of binary tree in the stack after recursive calls are made


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
    
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(lh-rh)>1)
            return false;
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        return (left && right);
    }
};

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=--------------------------------------------------------------------------------------------------+++++++++

// optimised solution
//tc: o(n) 
//sc: o(n) recursive call stack takes linear memory in case of a skew bt


class Solution {
public:
    int height(TreeNode *root)
    {
        if(!root)
            return 0;
        int lh=height(root->left);
        if(lh==-1)
            return -1;
        int rh=height(root->right);
        if(rh==-1)
            return -1;
        if(abs(lh-rh)>1)
            return -1;
        return max(lh, rh)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        return height(root)!=-1;
    }
};