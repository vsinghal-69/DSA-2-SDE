// Given an unsorted array in which every element represents the no of chocolates in that packet and the no of children.
//Distribute chocolate among these children such that every children gets only one packet and the difference between the no of chocolates received by each children should be minimum.
//,i.e., the children that received packet containing max no of chocolates and the children that received packet containing min no of chocolates, their difference should be minimum.

ex:
no of packets : 7
no of chocolates in each packets : 7 3 2 4 9 12 56
no of children : 3
output : 2

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-----------------------------------------------------------------++++++++

//algo : apply quicksort to sort the array in n*logn  time
// then, consider every element as the min element of the window of size equal to no of children

++++++++++++++++++++++++++++++++++++++++++++++++++++++----------------------------------------------------------------------------------------+++++++++++++++++++++++++++++++++++++++++++----

#include<bits/stdc++.h>
using namespace std;

int hore_p(int *a, int l, int r)
{
    int pivot = a[l];
    int i=l, j=r;
    while(1)
    {
        while(a[i]<pivot)++i;
        while(a[j]>=pivot)--j;
        if(i<j)
            swap(a[i], a[j]);
        else
            return i-1;
    }
}

void quicksort(int *a, int l, int r)
{
    if(l<r)
    {
        int p=hore_p(a,l,r);
        p=p<l?l:p;
        quicksort(a,l,p);
        quicksort(a,p+1,r);
    }
}

int choco(int *a, int n, int k)
{
    int md=INT_MAX;
    for(int i=0; i<=n-k; ++i)
    {
        md=min(md, a[i+k-1]-a[i]);
    }
    return md;
}

int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0; i<n; ++i)cin>>a[i];
    int c;
    cin>>c;
    quicksort(a, 0, n-1);
    cout<<choco(a,n,c);
    //for(int i=0; i<n; ++i)cout<<a[i]<<' ';
    return 0;
}
 