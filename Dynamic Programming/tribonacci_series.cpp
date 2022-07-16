//problem link : https://leetcode.com/problems/n-th-tribonacci-number/

/* The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn. 

 

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:

Input: n = 25
Output: 1389537 


Constraints: 
0 <= n <= 37

*/

----------------------------------------------------------------------------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// memoization or top-down approach
// tc: O(n)
// sc: O(n)

int memo(int n, int *dp)
    {
        if(dp[n]==-1)
        {
            if(n<=1)
                return n;
            if(n==2)
                return 1;
            dp[n]=memo(n-1, dp)+memo(n-2, dp)+memo(n-3, dp);
            //cout<<dp[n]<<' '<<"n = "<<n<<'\n';
        }
        return dp[n];
    }
    
    
    int tribonacci(int n) {
        int dp[38];
        for(int i=0; i<38; ++i)dp[i]=-1;
        return memo(n, dp);
    }


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// tabulation or bottom-up approach
// tc: O(n)
// sc: O(n)

int tribonacci(int n) {
        int dp[38];
        dp[0]=0, dp[1]=dp[2]=1;
        for(int i=3; i<=n; ++i)
        {
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }


---------------------------------------------------------------------------------------------

// space-optimised approach
//tc : O(n)
//sc : O(1)

int tribonacci(int n) {
        if(n<=1)
            return n;
        if(n==2)
            return 1;
        int a=0, b=1, c=1, d=0;
        for(int i=3; i<=n; ++i)
        {
            d=a+b+c;
            a=b, b=c, c=d;
        }
        return d;
    }