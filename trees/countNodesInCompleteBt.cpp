// problem link : https://leetcode.com/problems/count-complete-tree-nodes/

/*  Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity. */

=================================================================================================

// optimised solution
//tc: O(log(n)*log(n)) or square of log(n) bcz, at max we need to travel log(n) nodes, for every log(n) nodes, finding height will take log(n) time.
//sc: O(n) --> recursive call stack

 int iterative_lh(TreeNode *root)
    {
        int h=0;
        while(root)
        {
            ++h;
            root=root->left;
        }
        return h;
    }
    
    int iterative_rh(TreeNode *root)
    {
        int h=0;
        while(root)
        {
            ++h;
            root=root->right;
        }
        return h;
    }
    
    
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int lh=iterative_lh(root->left);
        int rh=iterative_rh(root->right);
        if(lh==rh)
            return pow(2, lh+1)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }