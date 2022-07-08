//problem link : https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

=====================================================================

/* Given a binary tree of nodes 'N', you need to modify the value of its nodes, such that the tree holds the Children sum property.
A binary tree is said to follow the children sum property if, for every node of that tree, the value of that node is equal to the sum of the value(s) of all of its children nodes( left child and the right child).
Note :
 1. You can only increment the value of the nodes, in other words, the modified value must be at least equal to the original value of that node.
 2. You can not change the structure of the original binary tree.
 3. A binary tree is a tree in which each node has at most two children.      
 4. You can assume the value can be 0 for a NULL node and there can also be an empty tree.*/

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++==============================================================================================

//optimised approach
//tc : o(n)
//sc : o(n) --> stack memory occupied by recursive calls

void changeTree(BinaryTreeNode < int > * root) {
    if(!root || (!root->left && !root->right))
        return;
    
    int l=0, r=0;
    if(root->left)
        l=root->left->data;
    if(root->right)
        r=root->right->data;
    
    if(root->data > l+r)  
    {
        if(root->left)
            root->left->data=root->data;
        if(root->right)
            root->right->data=root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    if(root->left)
        l=root->left->data;
    if(root->right)
        r=root->right->data;
    root->data=l+r;
}  