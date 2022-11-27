/* Problem link : https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article 

Problem name : No of distinct islands

Problem description : 

Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Example 2:

Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

Your Task:

You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1



*/



// solution : 

class Solution {
  public:
  
    int x[4]={-1, 0, +1, 0};
    int y[4]={0, +1, 0, -1};
    
    void dfs(vector<vector<int>>& grid, vector<pair<int, int>>& iland, int sr, int sc, vector<vector<int>>& vis, int &n, int &m, int &br, int &bc)
    {
        vis[sr][sc]=1;
        iland.push_back({sr-br, sc-bc});

        /*note... do not do iland.push_back({abs(sr-br), abs(sc-bc)});
            because it will coniser same for ..
            1    and    1
          1 1           1 1
        */

        for(int i=0; i<4; ++i)
        {
            int nr=sr+x[i];
            int nc=sc+y[i];
            if(nr>=0  && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc])
            {
                dfs(grid, iland, nr, nc, vis, n, m, br, bc);
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>>island;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(!vis[i][j] && grid[i][j])
                {
                    vector<pair<int, int>>iland;
                    dfs(grid, iland, i, j, vis, n, m, i, j);// 2nd i , j represnet starting point of dfs traversal of an island
                    island.insert(iland);
                }
            }
        }
        return island.size();
    }
};