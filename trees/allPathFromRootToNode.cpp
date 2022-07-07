// Problem link : https://leetcode.com/problems/binary-tree-paths/

/* Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children. */

============================================================================================

//optimised solution
// tc : O(n)
// sc : O(n)


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 void rootToNode(TreeNode *root, string s, vector<string>&ans)
    {
        if(!root)
        {
            return;
        }
        if(!root->left && !root->right)
        {
            ans.push_back(s+to_string(root->val));
            return;
        }
        rootToNode(root->left, s+to_string(root->val)+"->", ans);
        rootToNode(root->right, s+to_string(root->val)+"->", ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        rootToNode(root, "", ans);
        return ans;
    }