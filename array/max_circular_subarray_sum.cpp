//Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contiguous subarray sum.

/* N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output:
22
Explanation:
Starting from the last element
of the array, i.e, 12, and 
moving in a circular fashion, we 
have max subarray as 12, 8, -8, 9, 
-9, 10, which gives maximum sum 
as 22.*/

_____________________________________________________________________________________________________________________________________________________________________________________________

// quadratic solution and memory efficient

int circularSubarraySum(int arr[], int n){
        
        int msum=INT_MIN;
        for(int i=0; i<n; ++i)
        {
            int cs=0;
            for(int j=0; j<n; ++j)
            {
                cs+=arr[(i+j)%n];
                msum=max(msum, cs);
            }
        }
        return msum;
    }


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++---------------------------------------------------------------------------------------++++++++++

// quadratic solution but not memory efficient

int circularSubarraySum(int arr[], int n){
        
        int msum=INT_MIN;
        vector<int>v(2*n-1);
        for(int i=0; i<2*n; ++i)
        {
            v[i]=arr[i%n];
        }
        for(int i=0; i<n; ++i)
        {
            int cs=0;
            for(int j=i; j<i+n; ++j)
            {
                cs+=v[j];
                msum=max(msum, cs);
            }
        }
        return msum;
    }

+++++++++++++++++++++++++++++++++++++++++++=---------------------------------------------------------------------------------------------------------------------------++++++++++++++++++++++

//linear solution   ->>>> SEE GFG FOR ALGO

//function to compute min subarray sum;
    int min_sum(int a[], int n)
    {
        int minm_sum=0;
        int cs=0;
        for(int i=0; i<n; ++i)
        {
            cs+=a[i];
            minm_sum=min(cs, minm_sum);
            if(cs>0)
                cs=0;
        }
        return minm_sum;
    }
    
    // function to calculate max subarray sum;
     int max_sum(int a[], int n)
    {
        int msum=INT_MIN;
        int cs=0;
        for(int i=0; i<n; ++i)
        {
            cs+=a[i];
            msum=max(cs, msum);
            if(cs<0)
                cs=0;
        }
        return msum;
    }

    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int n){
        int nsum=max_sum(arr, n);
        if(nsum<0)
            return nsum;
        
        //calculating max sum among all circular subarray == array sum - min subarray sum.
        
        int asum=0;
        for(int i=0; i<n; ++i)
        {
            asum+=arr[i];
        }
        
        int csum= asum - min_sum(arr, n);
        return max(nsum, csum);
    }

