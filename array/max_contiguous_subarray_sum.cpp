// quadratic approach 

        long long maxSubarraySum(int arr[], int n){
        long long ans=INT_MIN;
        for(int i=0; i<n; ++i)
        {
            long long cs=0;
            for(int j=i; j<n; ++j)
            {
                cs+=arr[j];
                ans=max(ans, cs);
            }
        }
        return ans;
    }

// kadane's algo--> linear time
    long long maxSubarraySum(int arr[], int n){
        long long ans=INT_MIN;
        long long sum=0;
        for(int i=0; i<n; ++i)
        {
            sum+=arr[i];
            ans=max(ans, sum);
            if(sum<0)
                sum=0;
        }
        return ans;
    }


//linear time 
    long long maxSubarraySum(int arr[], int n){
        long long ans=INT_MIN;
        long long max_ending=0;
        for(int i=0; i<n; ++i)
        {
            max_ending=(max_ending+arr[i]>arr[i])?max_ending+arr[i]:arr[i];
            ans=max(ans, max_ending);
        }
         return ans;
    }
