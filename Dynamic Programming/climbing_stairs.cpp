//problem link : https://leetcode.com/problems/climbing-stairs/

/* 
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45 */

--------------------------------------------------------------------------------------------------------------------------------------------------->>>>>>>>>>>>


// NOTE : If the limit of n is greater than ~ 10^9, or the question constarints can't allow linear time, then solve this fibonacci sequence using Matrix Exponentiation
// Using Matrix exponentiation, fibonacci sequence can be solved in log(n) time complexity

---------------------------------------------------------------------------------------------------------------------------------------------------<<<<<<<<<<<<<

// memoization or top-down approach
//tc : O(n)
//sc : O(n)

int memo(int n, int *dp)
    {
        if(dp[n]==-1)
        {
            if(n<=2)
                return n;
            dp[n]=memo(n-1, dp)+memo(n-2, dp);
        }
        return dp[n];
    }
    
    int climbStairs(int n) {
        int dp[46];
        for(int i=0; i<=45; ++i)dp[i]=-1;
        return memo(n, dp);
    }

------------------------------------------------------------------------------------

//tabulation or bottom-up approach
//tc : o(n)
//sc : o(n)

int climbStairs(int n) {
        int dp[46];
        dp[0]=0, dp[1]=1, dp[2]=2;
        for(int i=3; i<=n; ++i)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

---------------------------------------------------------------------------------------

// space - optimised
//tc: O(n)
//sc: O(1)

int climbStairs(int n) {
        if(n<=2)
            return n;
        int a=1, b=2, c=0;
        for(int i=3; i<=n; ++i)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }