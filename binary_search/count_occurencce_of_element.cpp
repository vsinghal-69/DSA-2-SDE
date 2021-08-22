Given a sorted array of integers, find the number of occurrences of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return 0

**Example : **

Given [5, 7, 7, 8, 8, 10] and target value 8,

return 2.

___________________________________________________________________________________________________

//// this function returns first index where element x is present in vector, if not present returns -1

int fo(vector<int>a, int x)
{
    int s=0, e=a.size()-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(a[mid]<x)
            s=mid+1;
        else if(a[mid]>x)
            e=mid-1;
        else if(mid==0 || a[mid]!=a[mid-1])
            return mid;
        else
            e=mid-1;
    }
    return -1;
}

// this function returns last index where element x is present in vector, if not present returns -1
int lo(vector<int>a, int x)
{
    int s=0, e=a.size()-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(a[mid]<x)
            s=mid+1;
        else if(a[mid]>x)
            e=mid-1;
        else if(mid==a.size()-1 || a[mid]!=a[mid+1])
            return mid;
        else
            s=mid+1;
    }
    return -1;
}

//funcion to compute occurrences of element B in vextor A

int Solution::findCount(const vector<int> &A, int B) {
    int f=lo(A, B);
    if(f==-1)
        return 0;
    int l=lo(A, B);
    cout<<f<<' '<<l<<' ';
    return l-f+1;
}
