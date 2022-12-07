// Problem link : https://atcoder.jp/contests/dp/tasks/dp_c
// Problem link : https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?leftPanelTab=0

-----------------------------------------------------------------------------------------------------------------------------------------------------------------

C - Vacation  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 100 points

Problem Statement
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of N days. For each i (1≤i≤N), Taro will choose one of the following activities and do it on the i-th day:

A: Swim in the sea. Gain a 
i
​
  points of happiness.
B: Catch bugs in the mountains. Gain b 
i
​
  points of happiness.
C: Do homework at home. Gain c 
i
​
  points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.

Constraints
All values in input are integers.
1≤N≤10 
5
 
1≤a 
i
​
 ,b 
i
​
 ,c 
i
​
 ≤10 
4
 
Input
Input is given from Standard Input in the following format:

N
a 
1
​
  b 
1
​
  c 
1
​
 
a 
2
​
  b 
2
​
  c 
2
​
 
:
a 
N
​
  b 
N
​
  c 
N
​
 
Output
Print the maximum possible total points of happiness that Taro gains.

Sample Input 1 
Copy
3
10 40 70
20 50 80
30 60 90
Sample Output 1 
Copy
210
If Taro does activities in the order C, B, C, he will gain 70+50+90=210 points of happiness.

Sample Input 2 
Copy
1
100 10 1
Sample Output 2 
Copy
100
Sample Input 3 
Copy
7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1
Sample Output 3 
Copy
46
Taro should do activities in the order C, A, B, A, C, B, A.



----------------------------------------------------------------------------------------------------------------------------------------------------

// my memoization solution 
int solve(vector<vector<int>>& points, vector<vector<int>> &dp, int curr_day, int curr_task)
{
    if(curr_day==0)
    {
        return points[0][curr_task];
    }
    if(dp[curr_day][curr_task]==-1)
    {
        int maxi=-1;
        for(int i=0; i<3; ++i)
        {
            if(i!=curr_task)
            {
                maxi=max(maxi, points[curr_day][curr_task]+solve(points, dp, curr_day-1, i));
            }
        }
        dp[curr_day][curr_task]=maxi;
    }
    return dp[curr_day][curr_task];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n, vector<int>(3, -1));
    int ans=-1;
    for(int i=0; i<3; ++i)
    {
        ans = max(ans, solve(points, dp, n-1, i));
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<3; ++j)
            {
                dp[i][j]=-1;
            }
        }
    }
    return ans;
    /*n-1 represents the current day and i represents the task to be performed on curr day*/
}

-----------------------------------------------------------------------------------------------------------------------------------------------------
// striver memoization soln

int solve(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day==0)
    {
        int maxi=-1;
        for(int i=0; i<3; ++i)
        {
            if(i!=last)
            {
                maxi=max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last] == -1)
    {
        int maxi=-1;
        for(int i=0; i<3; ++i)
        {
            if(i!=last)
            {
                maxi=max(maxi, points[day][i]+solve(day-1, i, points, dp));
            }
        }
        dp[day][last]=maxi;
    }
    return dp[day][last];
}



int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n-1, 3, points, dp);
    /* n-1 represents the curr day and 3 represnets the last task performed*/
}


-----------------------------------------------------------------------------------------------------------------------------------------------------

// my tabulation soln
int ninjaTraining(int n, vector<vector<int>> &points)
{
    if(n==0)
        return 0;
    vector<vector<int>>dp{n, vector<int>(3, -1)};
    for(int i=0; i<3; ++i)
    {
        dp[0][i]=points[0][i];
    }
    for(int i=1; i<n; ++i)
    {
        dp[i][0]=points[i][0]+max(dp[i-1][1], dp[i-1][2]);
        dp[i][1]=points[i][1]+max(dp[i-1][0], dp[i-1][2]);
        dp[i][2]=points[i][2]+max(dp[i-1][0], dp[i-1][1]);
    }
     return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}
-------------------------------------------------------------------------------------------------------------------------------------------------------

// my spae optimised code

int ninjaTraining(int n, vector<vector<int>> &points)
{
    if(n==0)
        return 0;
    int prev=points[0][0];
    int prev1=points[0][1];
    int prev2=points[0][2];
    for(int i=1; i<n; ++i)
    {
        int curr=points[i][0]+max(prev1, prev2);
        int curr1=points[i][1]+max(prev, prev2);
        int curr2=points[i][2]+max(prev, prev1);
        prev=curr, prev1=curr1, prev2=curr2;
    }
     return max(prev, max(prev1, prev2));
}