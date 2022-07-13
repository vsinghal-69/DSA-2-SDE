// problem link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/

/* Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree. */

=========================================================

//optimised approach 
//tc: O(n)
//sc : O(n)


  TreeNode * build(vector<int>&preorder, int pstart, int pend, vector<int>&inorder, int istart, int iend, map<int, int>&inMap)
    {
        if(pstart>pend || istart>iend)
            return NULL;
        
        TreeNode *root=new TreeNode(preorder[pstart]);
        
        //Getting the position of  
        int inRoot = inMap[root->val];
        
        //countng element before root in inorder
        int left=inRoot-istart;
        
        root->left=build(preorder, pstart+1, pstart+left, inorder, istart, inRoot-1, inMap);
        root->right=build(preorder, pstart+left+1, pend, inorder, inRoot+1, iend, inMap);
        return root;
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int>inMap;
        for(int i=0; i<inorder.size(); ++i)
        {
            inMap[inorder[i]]=i;
        }
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    }