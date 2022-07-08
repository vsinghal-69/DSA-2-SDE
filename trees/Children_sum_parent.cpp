// problem link : https://practice.geeksforgeeks.org/problems/children-sum-parent/0/?track=DSASP-Tree&batchId=154#

/* Given a Binary Tree. Check whether all of its nodes have the value equal to the sum of their child nodes. */

==================================================================================================================

//optimised solution: 
//tc: O(n)
//sc: O(n) recursive calls occupy stack memory

//Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(!root || (!root->left && !root->right))
            return 1;
        int left=0, right=0;
        if(root->left)
            left=root->left->data;
        if(root->right)
            right=root->right->data;
        if(root->data != left+right || !(isSumProperty(root->left)&&isSumProperty(root->right)))
            return 0;
        return 1;
    }