Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.

input:
size of array : 19
array : 3, 18, 93, 53, 57, 2, 81, 87, 42, 66,90,45, 2,0, 41, 30, 32, 18,98
range : [22, 53]

output: 3 18 18 0 2 2 32 30 42 41 45 53 57 90 66 87 81 93 98

++++++++++++++++++++++++++++++++++++++++++++++++++----------------------------------------------------++++++++++++

#include<bits/stdc++.h>
using namespace std;

int hoare(vector<int>&a, int l, int r, int pivot)
{
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

//hoare partition to accumulate all elements equal to b just after all the smaller elements less than b resides
void ehoare(vector<int>&a, int l, int r, int pivot)
{

    int i=l, j=r;
    while(1)
    {
        while(a[i]==pivot)++i;
        while(a[j]>pivot)--j;
        if(i<j)
            swap(a[i], a[j]);
        else
            return;
    }
}

void rangep(vector<int>& arr,int a, int b)
{
    int n=arr.size();
    int p1=hoare(arr, 0, n-1, a);
    int p2=hoare(arr, p1+1, n-1, b);
    ehoare(arr, p2+1, n-1, b);
}


int main()
{
    vector<int>v{3, 18, 93, 53, 57, 2, 81, 87, 42, 66,90,45, 2,0, 41, 30, 32, 18,98};
    int a=22, b=53;
    rangep(v, a, b);
    for(auto x:v)cout<<x<<' ';
    return 0;
}
