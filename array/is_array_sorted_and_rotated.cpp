/*Given an array arr[] of N distinct integers, check if this array is Sorted (non-increasing or non-decreasing) and Rotated counter-clockwise. Note that input array may be sorted in either increasing or decreasing order, then rotated.
A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation.

Example 1:

Input:
N = 4
arr[] = {3,4,1,2}
Output: Yes
Explanation: The array is sorted 
(1, 2, 3, 4) and rotated twice 
(3, 4, 1, 2).
Example 2:

Input:
N = 3
arr[] = {1,2,3}
Output: No
Explanation: The array is sorted 
(1, 2, 3) is not rotated.*/


-------------------------------------------------------------------------------------------------------++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++----------------------------------

//linear time and constant space

bool checkRotatedAndSorted(int a[], int n){
        int mx=INT_MIN, mn=INT_MAX, mxi, mni;
        for(int i=0; i<n; ++i)
        {
            if(a[i]>mx)
            {
                mxi=i;
                mx=a[i];
            }
            if(a[i]<mn)
            {
                mni=i;
                mn=a[i];
            }
        }
         //cout<<mx<<' '<<mxi<<' '<<mn<<' '<<mni;
        
        // if array is sorted increasingly and rotated
        if(mxi==mni-1)
        {
            //element will be in incresing order from index 0 to mxi
            for(int i=0; i<mxi; ++i)
            {
                if(a[i]>a[i+1])
                    return 0;
            }
            //element starting from index mni to last index will be in incresing order
            for(int i=mni; i<n-1; ++i)
            {
                if(a[i]>a[i+1])
                    return 0;
            }
            if(a[0]<a[n-1])
            {
                return 0;
            }
          
        }
        // if array is sorted decreasingly and rotated
        else if(mxi==mni+1)
        {
            //element will be in decresing order from index 0 to mni
            for(int i=0; i<mni; ++i)
            {
                if(a[i]<a[i+1])
                {
                    return 0;
                }
            }
            //element starting from mxi to n will be in decresing order
            for(int i=mxi; i<n-1; ++i)
            {
                if(a[i]<a[i+1])
                    return 0;
            }
            if(a[0]>a[n-1])
            {
                return 0;
            }
        }
        // if not sorted in any order or sorted in any order but not rotated even once
        else
        {
            return 0;
        }
        return 1;
    }