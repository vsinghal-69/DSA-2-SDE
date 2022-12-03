// Problem link : https://leetcode.com/problems/house-robber-ii/description/

213. House Robber II
Medium
7.3K
108
Companies
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// memoization
//sc: linear
//tc :linear

int memoize(vector<int>&nums, int i, int *dp, int start)
    {
        if(i<start)
            return 0;
        if(i==start)
            return nums[start];
        if(dp[i]==-1)
        {
            dp[i]=max(nums[i]+memoize(nums, i-2, dp, start), memoize(nums, i-1, dp, start));
        }
        return dp[i];
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<0)
            return 0;
        if(n==1)
            return nums[0];
        int dp[n];
        for(int i=0; i<n; ++i)
        {
            dp[i]=-1;
        }
        int start1 = memoize(nums, n-1, dp, 1);
        for(int i=0; i<n; ++i)
        {
            dp[i]=-1;
        }
        int start0 = memoize(nums, n-2, dp, 0);
        return max(start1, start0);
    }

------------------------------------------------------------------------------------------------------------------------
//space-optimised
//sc: linear
//tc  : linear


int tabulation(vector<int>&nums, int start, int end)
    {
        if(end-start==0)//in case nums has only 2 elements
            return max(nums[start], nums[end]);
        int dp[nums.size()];
        dp[start]=nums[start];
        dp[start+1]=max(nums[start], nums[start+1]);
        for(int i=start+2; i<=end; ++i)
        {
            dp[i]=max(nums[i]+dp[i-2], dp[i-1]);
        }
        return dp[end];
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<0)
            return 0;
        if(n==1)
            return nums[0];
        return max(tabulation(nums, 0, n-2), tabulation(nums, 1, n-1));
    }
------------------------------------------------------------------------------------------------------------------------
//space-optimised
//sc: cosntant
//tc  : linear

int tabulation(vector<int>&nums, int start, int end)
    {
        if(end-start==0)//in case nums has only 2 elements
            return max(nums[start], nums[end]);
        int prev=nums[start];
        int prev2=max(nums[start], nums[start+1]);
        for(int i=start+2; i<=end; ++i)
        {
            int curr=max(nums[i]+prev, prev2);
            prev=prev2;
            prev2=curr;
        }
        return prev2;
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<0)
            return 0;
        if(n==1)
            return nums[0];
        return max(tabulation(nums, 0, n-2), tabulation(nums, 1, n-1));
    }