// in question frog jump, only 2 jumps were allowed from stairs, i.e, if at ith stair, then jumps allowed only to (i+1)th and (i+2)th stairs.
// this is the same ques, but with k jumps allowed, i.e., if at ith stair, then allowed jumps; --- [(i+1), (i+2), (i+3), ..........(i+k)th stairs].

-------------------------------------------------------------------------------------------------------------------------------------------------------

//memoization or top-down
//tc : O(n)*k
//sc : O(n)

int memo(int n, int k, int *dp, vector<int>&height)
{
    if(dp[n]==-1)
    {
        if(n==0)
            return 0;
        int mine=INT_MAX;
        int stepk=0;
        for(int i=1; i<=k; ++i)
        {
          if(n-i>=0)
            stepk = abs(height[n]-height[n-i])+memo(n-i, k, dp, height);
          mine=min(mine, stepk);
        }
        dp[n]=mine;
    }
    return dp[n];
}

int frogJump(int n, int k, vector<int> &heights)
{
    int dp[n];
    for(int i=0; i<n;++i)  
    {
        dp[i]=-1;
    }
    return memo(n-1, k, dp, heights);
}



->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//tabulation or bottom-up
//tc : O(n)*k
//sc : O(n)

int frogJump(int n, int k, vector<int> &heights)
{
    int dp[n];
    dp[0]=0;
    for(int i=1; i<n;++i)  
    {
        dp[i]=INT_MAX;
        for(int j=1; j<=k; ++j)
        {
          if(i-j >=0 )
          {
            dp[i]=min(dp[i], abs(heights[i]-heights[i-j])+dp[i-j]);
          }
        }
    }
    return dp[n-1];
}


->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// space - optimisation can not be done for this variation of frog jump, because k is not fixed and every time we can't make dynamically k variables.................