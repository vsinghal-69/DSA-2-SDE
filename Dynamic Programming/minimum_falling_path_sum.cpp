// problem link  :  https://leetcode.com/problems/minimum-falling-path-sum/

---------------------------------------------------------------------------------->>

931. Minimum Falling Path Sum
Medium
3.3K
100
Companies
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// memoization 
// tc : o(m*n)
// sc : o(m*n) + o(longest path)

class Solution {
public:
    int solve(vector<vector<int>>& dp, int& n, vector<vector<int>>& matrix, int row, int col)
    {
        if(row>=n || col<0 || col>=n)
            return INT_MAX;
        if(row==n-1)
            return matrix[row][col];
        if(dp[row][col]==-1)
        {
            dp[row][col]=matrix[row][col]+min(solve(dp, n, matrix, row+1, col-1), min(solve(dp, n, matrix, row+1, col), solve(dp, n, matrix, row+1, col+1)));
        }
        return dp[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int ans=INT_MAX;
        for(int i=0; i<n; ++i)
        {
            ans=min(ans, solve(dp, n, matrix, 0, i));
        }
        return ans;
    }
};


---------------------------------------------------------------------------------------

// tabulation
//tc : o(mn)
//sc : o(mn)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; ++i)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=0; i<n-1; ++i)// iterate from first row till 2nd last row
        {
            for(int j=0; j<n; ++j)
            {
                for(int k=-1; k<=1; ++k)
                {
                    if(j+k >= 0 && j+k <n)
                    {
                        dp[i+1][j] = min(dp[i+1][j], dp[i][j+k]);
                    }
                }
                dp[i+1][j]+=matrix[i+1][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0; i<n; ++i)
        {
            ans=min(ans, dp[n-1][i]);
        }
        return ans;
    }
};

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// space-optimization
//tc : o(mn)
//sc : o(n) // no of rows

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; ++i)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=0; i<n-1; ++i)// iterate from first row till 2nd last row
        {
            for(int j=0; j<n; ++j)
            {
                for(int k=-1; k<=1; ++k)
                {
                    if(j+k >= 0 && j+k <n)
                    {
                        dp[i+1][j] = min(dp[i+1][j], dp[i][j+k]);
                    }
                }
                dp[i+1][j]+=matrix[i+1][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0; i<n; ++i)
        {
            ans=min(ans, dp[n-1][i]);
        }
        return ans;
    }
};