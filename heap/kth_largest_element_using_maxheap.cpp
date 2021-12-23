/* Given an array arr[] of N positive integers and a number K. The task is to find the kth largest element in the array.

Example 1:

Input:
N = 5, K = 3
arr[] = {3, 5, 4, 2, 9}
Output: 
4 */


//Expected Time Complexity : O(NlogK)
//Expected Auxilliary Space : O(K)
+++++++++++++++++++++++++++++++++++++++++++++++++++++------------------------------------------------------------------------------------------------------------------++++++++++++++++++++++

//function to max heapify the bt
    void max_heapify(int arr[], int n, int i)
    {
        int li=i, lt=2*i+1, rt=2*i+2;
        if(lt<n && arr[lt]>arr[li])
        {
            li=lt;
        }
        if(rt<n && arr[rt]>arr[li])
        {
            li=rt;
        }
        if(i!=li)
        {
            swap(arr[li], arr[i]);
            max_heapify(arr, n, li);
        }
    }
    
    //function to extract the max(root) element from max heap bt
    void extract(int arr[], int &n)
    {
        swap(arr[0], arr[n-1]);
        --n;
        max_heapify(arr, n, 0);
    }
    
    //Function to return kth largest element from an array.
    int KthLargest(int arr[], int n, int k) {
        
        //firstly build a max heap;
        for(int i=(n-1)/2; i>=0; --i)
        {
            max_heapify(arr, n, i);
        }
        
        //extract k-1 top max elements 
        for(int i=1; i<k; ++i)
        {
            extract(arr, n);
        }
        return arr[0];
    }