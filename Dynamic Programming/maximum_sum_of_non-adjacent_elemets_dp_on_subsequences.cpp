// Problem link : https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

// leetcode same problem : https://leetcode.com/problems/house-robber/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// memoization 
//tc: linear
//sc: linear

int solve(vector<int>& nums, int dp[], int n)
{
    if(n<0)
        return 0;
    if(dp[n]==-1)
    {
        if(n==0)
        {
            dp[0]=nums[0];
        }
        else
        {
            dp[n]=max(nums[n]+solve(nums, dp, n-2), solve(nums, dp, n-1));
        }
    }
    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int dp[n];
    for(int i=0; i<n; ++i)
    {
        dp[i]=-1;
    }
    /* dp[i] represents the maximum sum of non-adjacent elemets conidered till index i so, dp[n-1] represnets the maximum sum of non-adjacent elemets considered for whole aaray elements*/
    solve(nums, dp, n-1);
    return dp[n-1];
    
}


-----------------------------------------------------------------------------------------------------------------------------------------------

// tabulation
// tc:linear
//sc: linear

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int dp[n];
    dp[0]=nums[0];
    if(n>=2)
        dp[1]=max(nums[0], nums[1]);
    for(int i=2; i<n; ++i)
    {
        dp[i]=max(nums[i]+dp[i-2], dp[i-1]);
    }
    return dp[n-1];
}

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//space-optimised 
//tc: linear
//sc: constant

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    if(n==1)
        return nums[0];
    if(n==2)
        return max(nums[0], nums[1]);
    int prev2=nums[0], prev1=max(nums[0], nums[1]);
    int curr;
    for(int i=2; i<n; ++i)
    {
        curr=max(nums[i]+prev2, prev1);
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}