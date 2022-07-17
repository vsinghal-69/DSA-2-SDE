// problem link : https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0

/*There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.
For Example
If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.
Input Format:
The first line of the input contains an integer, 'T,’ denoting the number of test cases.

The first line of each test case contains a single integer,' N’, denoting the number of stairs in the staircase,

The next line contains ‘HEIGHT’ array.
Output Format:
For each test case, return an integer corresponding to the minimum energy lost to reach the last stair.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 100000.
1 <= HEIGHTS[i] <= 1000 .

Time limit: 1 sec
Sample Input 1:
2
4

10 20 30 10
3
10 50 10
Sample Output 1:
20
0
Explanation Of Sample Input 1:
For the first test case,
The frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost).
Then a jump from the 2nd stair to the last stair (|10-20| = 10 energy lost).
So, the total energy lost is 20 which is the minimum. 
Hence, the answer is 20.

For the second test case:
The frog can jump from 1st stair to 3rd stair (|10-10| = 0 energy lost).
So, the total energy lost is 0 which is the minimum. 
Hence, the answer is 0.
Sample Input 2:
2
8
7 4 4 2 6 6 3 4 
6
4 8 3 10 4 4 
Sample Output 2:
7
2*/

---------------------------------------------------------------------------------------------------->>>>>>>>>>>>>>>>>.

//memoization or top-down
//tc : O(n)
//sc : O(n)

int memo(int n, int *dp, vector<int>&height)
{
    if(dp[n]==-1)
    {
        if(n==0)
            return 0;
        if(n==1)
            return abs(height[1]-height[0]);
        int step1 = abs(height[n]-height[n-1])+memo(n-1, dp, height);
        int step2 = abs(height[n]-height[n-2])+memo(n-2, dp, height);
        dp[n]=min(step1, step2);
    }
    return dp[n];
}

int frogJump(int n, vector<int> &heights)
{
    int dp[n];
    for(int i=0; i<n;++i)  
    {
        dp[i]=-1;
    }
    return memo(n-1, dp, heights);
}


--------------------------------------------------------------------------------------------------------------<<<<<<<<<<<<<<<<<<<<<<<<.

//tabulation or bottom up
//tc: O(n)
//sc: o(n)

int frogJump(int n, vector<int> &height)
{
    int dp[n];
    dp[0]=0;
    dp[1]=abs(height[1]-height[0]);
    for(int i=2; i<n;++i)  
    {
        int step1 = abs(height[i]-height[i-1])+dp[i-1];
        int step2 = abs(height[i]-height[i-2])+dp[i-2];
        dp[i]=min(step1, step2);
    }
    return dp[n-1];
}

.................................................................................................................................

//space-optimised
//tc: o(n)
//sc: o(1)

int frogJump(int n, vector<int> &height)
{
    int a=0, b=abs(height[1]-height[0]);
    if(n==1)
        return a;
    if(n==2)
        return b;
    int c=0;
    for(int i=2; i<n;++i)  
    {
        int step1 = abs(height[i]-height[i-1])+b;
        int step2 = abs(height[i]-height[i-2])+a;
        c=min(step1, step2);
        a=b, b=c;
    }
    return c;
}