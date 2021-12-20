/* Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.
   The element present at a particular index i in the sorted array is present in the range [i-k, i+k] in the input array.

   	n = 7, k = 3
	arr[] = {6,5,3,2,8,10,9}
	Output: 2 3 5 6 8 9 10
*/


-------------------------------------------------------------------------------------++++++++++++++++++++++++++++++++++++++++++++++++---------------------------------------------------------

// optimal solution using binary min heap of k+1 size.
// tc : o(n*log(k))
// sc : o(n)


// code


void min_heapify(int arr[], int n, int i)
    {
        int lt=2*i+1, rt=2*i+2, smlst=i;
        if(lt<n && arr[lt]<arr[smlst])
        {
            smlst=lt;
        }
        if(rt<n && arr[rt]<arr[smlst])
        {
            smlst=rt;
        }
        if(i!=smlst)
        {
            swap(arr[smlst], arr[i]);
            min_heapify(arr, n, smlst);
        }
    }
    
    
    
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        vector<int>ans;
        
        // build heap for first k+1 elements.
        for(int i=(k-1)/2; i>=0; --i)
        {
            min_heapify(arr, k+1, i);
        }
        
        // iterate from k+1 index to last index and extract min and then replace root by current index and then mean_heapify to bring the minimum element at the top
        for(int i=k+1; i<n; ++i)
        {
            ans.push_back(arr[0]);
            arr[0]=arr[i];
            min_heapify(arr, k+1, 0);
        }
        
        // now our first k+1 element from index 0 to index k is left in binary tree.and minimum is alraedy present at the top. so, extract minimum amd reduce the bt size by 1 and then again mean heapify to bring the minimum element at top untill there is only 1 element left in bt.
        int size=k+1;
        while(size>1)
        {
            ans.push_back(arr[0]);
            arr[0]=arr[size-1];
            --size;
            min_heapify(arr, size, 0);
        }
         ans.push_back(arr[0]);
        return ans;
    }