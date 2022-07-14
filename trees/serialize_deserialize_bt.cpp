//problem link : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/* Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.*/


------------------------------------------------------------------------------------------------------

// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(!root)
            return ans;
        queue<TreeNode *>q;
        q.push(root);
        ans+=to_string(root->val);
        ans+=',';
        while(!q.empty())
        {
            TreeNode *p=q.front();
            q.pop();
            if(p->left)
            {
                ans+=to_string(p->left->val);
                q.push(p->left);
            }
            else
            {
                ans+='$';
            }
            ans+=',';
            if(p->right)
            {
                ans+=to_string(p->right->val);
                q.push(p->right);
            }
            else
            {
                ans+='$';
            }
            if(q.size())
                ans+=',';
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data=="")
            return NULL;
        queue<TreeNode *>q;
        string x="";
        int i=0;
        while(i<data.size() && data[i]!=',')
        {
            x+=data[i];
            ++i;
        }
        ++i;
        
        TreeNode *root = new TreeNode(stoi(x));
        q.push(root);
        while(!q.empty())
        {
            TreeNode *root=q.front();
            q.pop();
            if(data[i]!='$')
            {   string x;
                while(i<data.size() && data[i]!=',')
                {
                    x+=data[i];
                    ++i;
                }
                root->left=new TreeNode(stoi(x));
                 q.push(root->left);
             ++i;
            }
            else
            {
                root->left=NULL;
                i+=2;
            }
            if(data[i]!='$')
            {
                string x;
                while(i<data.size() && data[i]!=',')
                {
                    x+=data[i];
                    ++i;
                }
               
                root->right=new TreeNode(stoi(x));
                 q.push(root->right);
                i+=1;
            }
            else
            {
                root->right=NULL;
                i+=2;
            }
           
        }
        return root;
    }

