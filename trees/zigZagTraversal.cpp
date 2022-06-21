/* Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).*/

//optimised solution
//tc: o(n)
//sc: o(n) recursive call stack memory

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


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<TreeNode *>q;
        q.push(root);
        bool l2r=1; // l2r means that level should be from left to right in the ans
        while(!q.empty())
        {
            int size=q.size();
            vector<int>v(size);
            for(int i=0; i<size; ++i)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(l2r)
                {
                    v[i]=temp->val;
                }
                else
                {
                    v[size-1-i]=temp->val;
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            l2r=!l2r;
            ans.push_back(v);
        }
        return ans;
    }
};