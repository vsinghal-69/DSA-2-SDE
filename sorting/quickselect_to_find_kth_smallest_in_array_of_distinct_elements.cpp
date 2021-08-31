// Given an array of distinct elements, find the kth smallest element in array without sorting the array and without using extra space
// constraints: k is always lesser than or equal to the size of input array

Example 1:
Input: 
N = 5, K = 3
arr[] = {3,5,4,2,9}
Output: 
4
Explanation: 
Third smallest element in the array is 4.
Example 2:

Input:
N = 5, k = 5
arr[] = {4,3,7,6,5}
Output: 
7
Explanation: 
Fifth smallest element in the array is 7.

++++++++++++++++++++++++++++++++++++++++++++__--------------------------------------------------------++++++++++++++++++++++++

//function to implement lomuto partition and return the correct index where pivot has been inserted
    //in lomuto partition, pivot is always taken as the last element of the given range.
    int lomuto(int *a, int l, int h)
    {
        int i=l, j=l;//i points to element where our smaller element can be put.
        //a[h] is considered as pivot element.
       // we have to partition the array in such a way that all elements on the left side of pivot are strictly smaller than pivot and on the righ may be equal or greater than pivot
       
        for(; j<=h-1; ++j)
        {
            if(a[j]<a[h])
            {
                swap(a[i], a[j]);
                ++i;
            }
        }
        swap(a[h], a[i]);//at last swap the pivot element with its correct position
        return i;//returning the index of the pivot element
    }
    

    //Function to find the kth smallest element in the array.
    int kthSmallest(int a[], int n, int k)
    {
        int l=0, r=n-1;
        while(l<=r)
        {
            int p=lomuto(a, l, r);
            if(p==k-1)
                return a[p];
            else if(p<k-1)
                l=p+1;
            else
                r=p-1;
        }
    }