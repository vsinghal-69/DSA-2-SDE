//Problem link : https://leetcode.com/problems/minimum-path-sum/description/

----------------------------------------------------------------------------

64. Minimum Path Sum
Medium
9.1K
117
Companies
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100


=======================================================================================================================

// memoization
//tc : o(m*n)
//sc: o(m*n)+stack space of longest path(m+n)

class Solution {
public:
    int memoize(vector<vector<int>>&dp, vector<vector<int>>&grid, int m, int n)
    {
        if(m<0 || n<0)
            return INT_MAX;
        if(m==0 && n==0 )
            return grid[0][0];
        if(dp[m][n]==-1)
        {
            dp[m][n]= grid[m][n]+min(memoize(dp, grid, m-1, n), memoize(dp, grid, m, n-1));
        }
        return dp[m][n];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return memoize(dp, grid, m-1, n-1);
    }
};

-------------------------------------------------------------------------------------------------------------------

// tabulation
//tc: o(m*n)
//sc : 0(m*n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        dp[0][0]=grid[0][0];
        for(int i=1; i<m; ++i)
        {
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1; i<n; ++i)
        {
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int i=1; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                dp[i][j]=min(dp[i-1][j], dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

