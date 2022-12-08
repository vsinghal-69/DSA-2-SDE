// Problem link : https://leetcode.com/problems/triangle/description/

---------------------------------------------------------------------------

120. Triangle
Medium
7.3K
453
Companies
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?

------------------------------------------------------------------------------------------------------------------------------------

// memeoization 
// tc : o(total no of elemets)
// sc : stack space of longest path + 0(total elements)

class Solution {
public:
    int solve(int m, vector<vector<int>>& triangle, int row, int col, vector<vector<int>>&dp)
    {
        if(row==m-1)
        {
            return triangle[row][col];
        }
        if(dp[row][col]==-1)
            dp[row][col]= triangle[row][col]+min(solve(m, triangle, row+1, col, dp), solve(m, triangle, row+1, col+1, dp));
        return dp[row][col];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[0].size();
        vector<vector<int>>dp(m);
        for(int i=0; i<m; ++i)
        {
            vector<int>v(triangle[i].size(), -1);
            dp[i]=v;
        }
        return solve(m, triangle, 0, 0, dp);
    }
};

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// tabulation 
// tc : o(total no of elemets)
// sc : 0(total elements)

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[0].size();
        vector<vector<int>>dp(m);
        for(int i=0; i<m; ++i)
        {
            vector<int>v(triangle[i].size(), -1);
            dp[i]=v;
        }
        dp[0][0]=triangle[0][0];
        for(int i=1; i<m; ++i)
        {
            int cs=triangle[i].size();
            for(int j=0; j<cs; ++j)
            {
                if(j==0)
                    dp[i][j]=triangle[i][j]+dp[i-1][j];
                else if(j==cs-1)
                    dp[i][j]=triangle[i][j]+dp[i-1][j-1];
                else
                    dp[i][j]=triangle[i][j]+min(dp[i-1][j], dp[i-1][j-1]);
            }
        }
        int ans=INT_MAX;
        for(int i=0; i<dp[m-1].size(); ++i)
        {
            ans=min(ans, dp[m-1][i]);
        }
        return ans;
    }
};

-------------------------------------------------------------------------------------------------------------------------------------

// space-optimisation
//tc: o(no of elemets)
//sc : o(no of rows)

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
    int m=triangle.size();
    vector<int>v(m, 0);// vcetor of size equal to no of rows to accomodate maximum no of elemets in last row
    v[0]=triangle[0][0]; 
    for(int i=1; i<m; ++i)
    {
        int prev_diag=INT_MAX;
        for(int j=0; j<i; ++j)// itearting over the preceding row to i
        {
            //update for the rows in current row elemets, i.e., i 
            int diag=v[j];
            v[j]=triangle[i][j]+min(v[j], prev_diag);
            prev_diag=diag;
            
        }
        v[i]=prev_diag+triangle[i][i];
    }
    int ans=INT_MAX;
    for(int i=0; i<m; ++i)ans=min(ans, v[i]);
    return ans;
    }  
};

