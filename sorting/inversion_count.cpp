Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).


Example 2:

Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count. 
_________________________________________________________________________________________________________________________

// function where merging takes place and counting of inversions.

long long int merge_ic(long long *a, long long l, long long mid, long long r)
    {
        long long  s1=mid-l+1, s2=r-mid;
        long long  a1[s1];
        long long  a2[s2];
        long long k=l;
        for(int i=0; i<s1; ++i)
        {
            a1[i]=a[k++];
        }
        for(int i=0; i<s2; ++i)
        {
            a2[i]=a[k++];
        }
        long long res=0, i=0, j=0;
        k=l;
        while(i<s1 && j<s2)
        {
            if(a1[i]<=a2[j])
            {
                a[k++]=a1[i++];
            }
            else
            {
                a[k++]=a2[j++];
                //if element in a2 is smaller than any element of a1, then it is a inversion
                res+=s1-i;//this line performs counting of more than one inversion at a time.
            }
        }
        while(i<s1)
        {
            a[k++]=a1[i++];
        }
        while(j<s2)
        {
            a[k++]=a2[j++];
        }
        return res;
    }
    
    //function for merge sort and returning inversions

    long long int ic(long long *a, long long l, long long r)
    {
        long long int res=0;
        if(l<r)
        {
            long long  mid=l+(r-l)/2;
            res+=ic(a, l, mid);
            res+=ic(a, mid+1, r);
            res+=merge_ic(a, l, mid, r);
        }
        return res;
    }
    
 // the function calling mergesort and returning inversion count to main function

    long long int inversionCount(long long *a, long long n)
    {
         long long ans= ic(a, 0, n-1);
         return ans;
    }