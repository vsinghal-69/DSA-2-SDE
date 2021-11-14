//Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.

/* Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10 */

_________________________________________________________________________________________________________________________________________________________________

//linear time complexity and space complexity

  long long trappingWater(int arr[], int n){
        long long ans=0;
        if(n<3)
            return ans;
        int lm[n]={arr[0]};
        for(int i=1; i<n; ++i)
        {
            lm[i]=max(lm[i-1], arr[i]);
        }
        int rm[n]={0};
        rm[n-1]=arr[n-1];
        for(int i=n-2; i>=0; --i)
        {
            rm[i]=max(rm[i+1], arr[i]);
        }
        
        for(int i=1; i<=n-2; ++i)
        {
            ans+=min(lm[i], rm[i])-arr[i];
        }
        return ans;
    }

// linear time complexity and constant space --> most efficient approach
  
  long long trappingWater(int arr[], int n){
        long long ans=0;
        if(n<3)
            return ans;
        int l=0, r=n-1;
        int lm=arr[0], rm=arr[n-1];
        while(l<=r)
        {
            if(arr[l]<=arr[r])
            {
                if(arr[l]>=lm)
                {
                   lm=arr[l];     
                }
                else
                {
                    ans+=lm-arr[l];
                }
                ++l;
            }
            else
            {
                if(arr[r]>=rm)
                {
                    rm=arr[r];
                }
                else
                {
                    ans+=rm-arr[r];
                }
                --r;
            }
        }
        return ans;
    }