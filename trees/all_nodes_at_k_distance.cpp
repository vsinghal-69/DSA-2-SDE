// problem link : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/

/*  Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order. */

=========================================================================================================================

//optimised approach : 

//tc: o(n)
//sc :linear

  void parentNode(TreeNode *root, unordered_map<TreeNode *, TreeNode *>&m)
    {
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *p=q.front();
            q.pop();
            if(p->left)
            {
                q.push(p->left);
                m[p->left]=p;
            }
            if(p->right)
            {
                q.push(p->right);
                m[p->right]=p;
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(!root)
            return ans;
        // firstly create an unordered map where key is node and value is their parent node
        // this node to their parent hashing will help to travel a node back to their parent[upward]
        unordered_map<TreeNode *, TreeNode *>m;
        parentNode(root, m);
        int dist=0;
        queue<TreeNode *>q;
        q.push(target);
        unordered_map<TreeNode *, bool>visited; // maintains a hash of visited nodes
        visited[target]=true;
        bool flag=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                if(dist==k)
                {
                    flag=1;
                    break;
                }
                TreeNode *p=q.front();
                q.pop();
                if(p->left && !visited[p->left])
                {
                    q.push(p->left);
                    visited[p->left]=1;
                }
                if(p->right && !visited[p->right])
                {
                    q.push(p->right);
                    visited[p->right]=1;
                }
                if(m[p] && !visited[m[p]])
                {
                    q.push(m[p]);
                    visited[m[p]]=1;
                }
            }
            ++dist;
            if(flag)
                break;
        }
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }