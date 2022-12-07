// Problem link : https://leetcode.com/problems/unique-paths-ii/description/

63. Unique Paths II
Medium
6.3K
423
Companies
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// memoization 
//tc: o(m*n)
//sc : o(m*n)+o(m+n)

class Solution {
public:
    int memoize(int up, int left, vector<vector<int>>&dp, vector<vector<int>>& grid)
    {
        if(up<0 || left<0)
            return 0;
        if(grid[up][left]==1)
        {
            dp[up][left]=0;
        }
        if(dp[up][left]==-1)
        {
            if(up==0 && left==0)
            {
                dp[up][left]=1;
                return 1;
            }
            dp[up][left]=memoize(up-1, left, dp, grid)+memoize(up, left-1, dp, grid);
        }
        return dp[up][left];
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return memoize(m-1, n-1, dp, obstacleGrid);
    }
};

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// tabulation 
//tc: m*n
sc : o(m*n)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(obstacleGrid[i][j])
                    dp[i][j]=0;
                else if(i==0 && j==0)
                    dp[i][j]=1;
                else
                {
                    int up =0, left=0;
                    if(i-1 >=0 )
                        up=dp[i-1][j];
                    if(j-1 >=0 )
                        left=dp[i][j-1];
                    dp[i][j]=up + left;
                }
                
            }
        }
        return dp[m-1][n-1];
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------------
