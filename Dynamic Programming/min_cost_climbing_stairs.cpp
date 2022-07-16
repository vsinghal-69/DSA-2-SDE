//problem link : https://leetcode.com/problems/min-cost-climbing-stairs/

/*You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999*/





----------------------------------------------------------------------------------------------------------------------------------------------------------------------->>>>>>>>>>>>

// in this ques, we need to start from 0th or 1st step and then return the minimum of path cost at n-2th(second last step) and n-1th (last step) step. 

---------------------------------------------------------------------------------------------------------------------------------------------------------------
//memoization or top down
//tc: o(n)
//sc : o(n)

  int memo(int i, int *dp, vector<int>& cost)
    {
        if(dp[i]==-1)
        {
            if(i<=1)
                return cost[i];
            dp[i]=cost[i]+min(memo(i-1, dp, cost), memo(i-2, dp, cost));
        }
        return dp[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp[n];
        for(int i=0; i<n; ++i)
        {
            dp[i]=-1;
        }
        return min(memo(n-1, dp, cost), memo(n-2, dp, cost));
    }

---------------------------------------------------------------------------------------------------------------------------------------------------------------
//tabulation or bottom up
//tc: o(n)
//sc : o(n)

 int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp[n];
        dp[0]=cost[0], dp[1]=cost[1];
        for(int i=2; i<n; ++i)
        {
            dp[i]=cost[i]+min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }

---------------------------------------------------------------------------------------------------------------------------------------------------------------
//space optimized
//tc: o(n)
//sc : o(1)

int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        int a=cost[0], b=cost[1];
        if(n<=2)
            return min(a, b);
        int c=0;
        for(int i=2; i<n; ++i)
        {
            c=cost[i]+min(a, b);
            a=b;
            b=c;
        }
        return min(c, a); 
	//here we are returning min(c, b), but as b value has been updated to c in last iteration of for loop and last value of b is stored in a so, return min(c, a)  
	//c represents mincost value at n-1th step and b represents the n-2th step or second last step. 
    }

