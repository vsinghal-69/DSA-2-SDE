/*Given an array arr[] of N positive integers and a number K. The task is to find the kth smallest element in the array.
Input: 
N = 5, K = 3
arr[] = {3,5,4,2,9}

Output: 
4 */

//Expected Time Complexity: O(NlogK)
//Expected Auxilliary Space: O(K)
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-----------------------------------------------------------------------+++++++++++++++++++++++++++++++++


 //function to min_heapify the bt
    void min_heapify(int arr[], int n, int i)
    {
        int si=i, lt=2*i+1, rt=2*i+2;
        if(lt<n && arr[lt]<arr[si])
        {
            si=lt;
        }
        if(rt<n && arr[rt]<arr[si])
        {
            si=rt;
        }
        if(i!=si)
        {
            swap(arr[si], arr[i]);
            min_heapify(arr, n, si);
        }
    }
    
    //Function to extract the min or root element from the min heap bt
    
    void extract(int arr[], int &n)
    {
        swap(arr[0], arr[n-1]);
        --n;
        min_heapify(arr, n, 0);
    }
    
    //Function to find the kth smallest element in the array.
    int kthSmallest(int arr[], int n, int k)
    {
        // firstly build the min heap
        for(int i=(n-1)/2; i>=0; --i)
        {
            min_heapify(arr, n, i);
        }
        
        //extract k-1 top min elements
        for(int i=1; i<k; ++i)
        {
            extract(arr, n);
        }
        return arr[0];
    }