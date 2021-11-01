// Leetcode 26. Remove Duplicates from Sorted Array

int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(!n)
            return 0;
        
        /* quadratic solution
        int i=1;
        for(; i<n; ++i)
        {
            if(nums[i]<=nums[i-1])
            {
                int j=i+1;
                for(; j<n; ++j)
                {
                    if(nums[j]>nums[i-1])
                        break;
                }
                if(j==n)
                    return i;
                else
                {
                    nums[i]=nums[j];
                }
            }
        }
        return n; */
        
        //linear solution using 2 pointer
        int left=1; /*correct index pos. where newly found distinct element has to be inserted
        and left also indicates the tot. no of distinct elements found till index i */
        for(int i=1; i<n; ++i)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[left]=nums[i];
                ++left;
            }
        }
        return left;
            
    }