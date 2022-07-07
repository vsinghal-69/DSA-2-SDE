// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center.

//logic--> start from the left sub tree root(root->left) and the right sub tree root(root->right)
// traverse in style [root->left->right] for left sub tree and [root->right->left] for right sub tree, and every node should be equal for both left and right subtree

=================================================================================================================================================================================

//optimised approach
//tc: O(n)
//sc: O(n)


++++++++++++++++++++++++++++++++++++++++

 bool check(TreeNode *root1, TreeNode *root2)
    {
        if(!root1 || !root2)
            return root1==root2;
        if(root1->val != root2->val)
            return false;
        return check(root1->left, root2->right)&&check(root1->right, root2->left);
    }
    
    
    bool isSymmetric(TreeNode* root) {
        return (root==NULL || check(root->left, root->right));
    } 