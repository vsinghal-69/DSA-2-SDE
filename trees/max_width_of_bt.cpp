// problem link : https://leetcode.com/problems/maximum-width-of-binary-tree/

/* Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer. */

=================================================================================================

//optimised solution
//tc : O(n)
//sc: O(n)

int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans=0;
        queue<pair<TreeNode *, int>>q;
        q.push({root, 0});
        while(!q.empty())
        {
            int size=q.size();
            int lowest=q.front().second;
            int highest;
            for(int i=0; i<size; ++i)
            {
                auto p=q.front();
                q.pop();
                TreeNode *curr=p.first;
                long index=p.second; //use long to avoid integer overflow while multiplying by 2
                if(i==size-1)
                    highest=index;
                if(curr->left)
                    q.push({curr->left, 2*(index-lowest)+1}); // index - lowest to prevent integer overflow
                if(curr->right)
                    q.push({curr->right, 2*(index-lowest)+2});
            }
            ans=max(ans, highest-lowest+1);
        }
        return ans;
    }