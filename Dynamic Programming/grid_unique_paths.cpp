// Problem link : https://leetcode.com/problems/unique-paths/description/
-------------------------------------------------------------------------

62. Unique Paths
Medium
12.4K
360
Companies
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100
------------------------------------------------------------------------------------------------------------

// memoization soln 
//tc : m*n
// sc: m*n + stack memory of longest path(m+n)

class Solution {
public:
    int memoize(int up, int left, vector<vector<int>>&dp)
    {
         if(up==0 && left==0)
            return 1;
        if(up<0 || left<0)
            return 0;
        if(dp[up][left]==-1)
        {
            dp[up][left]=memoize(up-1, left, dp)+memoize(up, left-1, dp);
        }
        return dp[up][left];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return memoize(m-1, n-1, dp);
    }
};

----------------------------------------------------------------------------------------------

// tabulation 
// tc: o(m*n)
//sc : o(m*n)

int uniquePaths(int m, int n) {
        if(m==0 || n==0)
            return 0;
        vector<vector<int>>dp(m, vector<int>(n, -1));
        for(int i=0; i<m; ++i)
        {
            dp[i][0]=1;
        }
        for(int i=0; i<n; ++i)
        {
            dp[0][i]=1;
        }
        for(int i=1; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

--------------------------------------------------------------------------------------------------

// space-optimization
//tc : o(m*n)
//sc : constant

class Solution {
public:
    
    int uniquePaths(int m, int n) {
        if(m==0 || n==0)
            return 0;
        int prev_row[n];
        for(int i=0; i<n; ++i)
        {
            prev_row[i]=1;
        }
        for(int i=1; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                prev_row[j]=prev_row[j]+prev_row[j-1];
            }
        }
        return prev_row[n-1];
    }
};
