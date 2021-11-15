
//quadratic method
int maxEvenOdd(int arr[], int n) 
    { 
       if(!n)
        return 0;
       int ans=1;
       for(int i=0; i<n-1; ++i)
       {
           int cl=1;
           for(int j=i+1; j<n; ++j)
           {
               if((arr[j]%2 && arr[j-1]%2==0) || (arr[j]%2==0 && arr[j-1]%2))
                {
                    ++cl;
                    ans=max(ans, cl);
                }
               else
               {
                   break;
               }
           }
       }
       
       return ans;
    } 


// linear method using kadane's algo concept
       int cl=1;
       for(int i=1; i<n; ++i)
       {
           if((arr[i]%2 && arr[i-1]%2==0) || (arr[i]%2==0 && arr[i-1]%2))
           {
               ++cl;
               ans=max(ans, cl);
           }
           else
           {
               cl=1;
           }
       }