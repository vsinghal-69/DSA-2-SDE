//problem link : https://www.interviewbit.com/problems/burn-a-tree/

// NOTE: This solution is compatible for all nodes. So, we can start fire from any node in the binary tree


=======================================================================================================================================

/* Given a binary tree denoted by root node A and a leaf node B from this tree.

 It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on.

You need to find the minimum time required to burn the complete binary tree. */

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// optimised approach 
//tc: O(n)
//sc: O(n)



// traverse the binary tree and store the parent node corresponding to every node so, that we can use it later to travel in upward direction(i.e., from child node to their parent node)
TreeNode * traverse(TreeNode *root, unordered_map<TreeNode *, TreeNode *>&parent, int target)
    {
        TreeNode *target_Node;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *p=q.front();
            q.pop();
            
            if(p->val==target)
                target_Node=p;
            
            if(p->left)
            {
                q.push(p->left);
                parent[p->left]=p;
            }
            if(p->right)
            {
                q.push(p->right);
                parent[p->right]=p;
            }
        }
        return target_Node;
    }
   
 

int Solution::solve(TreeNode* root, int target) {
    int ans=0;
        if(!root)
            return ans;
        unordered_map<TreeNode *, TreeNode *>parent; // stores nodes as key and their respective parent node as value
        TreeNode *targetNode = traverse(root, parent, target);
        
        queue<TreeNode *>q;
        q.push(targetNode);
        
        unordered_map<TreeNode *, bool>visited;
        visited[targetNode]=1;
        
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode *curr=q.front();
                q.pop();
                
                if(curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left]=1;
                }
                
                if(curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right]=1;
                }
                
                if(parent[curr] && !visited[parent[curr]])
                {
                    q.push(parent[curr]);
                    visited[parent[curr]]=1;
                }
            }
            if(q.size())
                ++ans;
        }
        return ans;
}
