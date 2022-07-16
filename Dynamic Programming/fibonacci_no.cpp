// problem link : https://leetcode.com/problems/fibonacci-number/

/* The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

 

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

Constraints:

0 <= n <= 30
*/


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>>>

// NOTE : If the limit of n is greater than ~ 10^9, or the question constarints can't allow linear time, then solve this fibonacci sequence using Matrix Exponentiation
// Using Matrix exponentiation, fibonacci sequence can be solved in log(n) time complexity

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>>>


// memoization or top-down
//tc: O(n)
//sc: O(n)

int memo(int n, int*dp)
    {
        if(dp[n]==-1)
        {
            if(n<=1)
                return n;
            dp[n]=memo(n-1, dp)+memo(n-2, dp);
        }
        return dp[n];
    }
    
    
    int fib(int n) {
        int dp[31];
        for(int i=0; i<=30; ++i)dp[i]=-1;
        return memo(n, dp);
    }


--------------------------------------------------------------------------------->>>>>

// tabulation or bottom-up
//tc: O(n)
//sc: O(n)

int fib(int n) {
        int dp[31];
        dp[0]=0, dp[1]=1;
        for(int i=2; i<=n; ++i)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

------------------------------------------------------------------------------->>>>>

//space optimised
//tc: o(N)
//sc: O(1)

int fib(int n) {
        if(n<=1)
            return n;
        int a=0, b=1, c=0;
        for(int i=2; i<=n; ++i)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }

