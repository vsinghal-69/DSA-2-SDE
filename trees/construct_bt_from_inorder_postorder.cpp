//problem link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/

/* Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree. */

======================================================================================================================

//optimised approach
//tc: O(n*logn)  --> n to traverse all the nodes and logn to access key value pair from map for every node
//sc: o(n)

 
    TreeNode * build(vector<int>&inorder, int istart, int iend, vector<int>&postorder, int pstart, int pend, map<int, int>&inMap)
    {
        if(istart>iend || pstart>pend)
            return NULL;
        TreeNode *root=new TreeNode(postorder[pend]);
        int inRoot=inMap[postorder[pend]];
        int left=inRoot-istart;
        
        root->left=build(inorder, istart, inRoot-1, postorder, pstart, pstart+left-1, inMap );
         root->right=build(inorder, inRoot+1, iend, postorder, pstart+left, pend-1, inMap );
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int>inMap;
        for(int i=0; i<inorder.size(); ++i)
        {
            inMap[inorder[i]]=i;
        }
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
    }