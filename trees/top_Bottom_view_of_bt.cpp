 // optimised approach
// tc: o(n)
//sc: o(n)

//Function to return a list of nodes visible from the top view from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
         vector<int>ans;
        if(!root)
            return ans;
        map<int, int>m;
        queue<pair<Node *, int>>q;
        q.push({root, 0});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            Node *temp=p.first;
            int vertical=p.second;
            if(m.find(vertical)==m.end())
            {
                m[vertical]=temp->data;
            }
                
            if(temp->left)
            {
                q.push({temp->left, vertical-1});
            }
            if(temp->right)
            {
                q.push({temp->right, vertical+1});
            }
        }
        for(auto x:m)ans.push_back(x.second);
        return ans;
    }

===================================================================================================================================================

 // optimised approach
// tc: o(n)
//sc: o(n)

// Function to return a list of nodes visible from the bottom view from left to right in Binary Tree.
vector <int> bottomView(Node *root) {
        vector<int>ans;
        if(!root)
            return ans;
        map<int, int>m;
        queue<pair<Node *, int>>q;
        q.push({root, 0});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            Node *temp=p.first;
            int vertical=p.second;
            m[vertical]=temp->data;
            if(temp->left)
            {
                q.push({temp->left, vertical-1});
            }
            if(temp->right)
            {
                q.push({temp->right, vertical+1});
            }
        }
        for(auto x:m)ans.push_back(x.second);
        return ans;
    }