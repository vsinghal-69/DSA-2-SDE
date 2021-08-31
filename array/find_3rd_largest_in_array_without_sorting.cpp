#include<bits/stdc++.h>
using namespace std;

// function to find the third largest element in array without sorting and using extra space
int klarge(int *a, int n)
{
    if(n<3)
        return -1;
    int fl=a[0], sl=INT_MIN, tl=INT_MIN;
    for(int i=1; i<n; ++i)
    {
        if(a[i]>fl)
        {
            tl=sl;
            sl=fl;
            fl=a[i];
        }
        else if(a[i]>sl)
        {
            tl=sl;
            sl=a[i];
        }
        else if(a[i]>tl)
        {
            tl=a[i];
        }
    }
    return tl;
}




//function to find the second smallest element in the array without sorting and using auxiliary space
int ksmall(int *a, int n)
{
    if(n<2)
        return -1;
    int fs=a[0], sc=INT_MAX;
    for(int i=1; i<n; ++i)
    {
        if(a[i]<fs)
        {
            sc=fs;
            fs=a[i];
        }
        else if(a[i]<sc)
        {
            sc=a[i];
        }
    }
    return sc;
}

int main()
{
    int n;
    cin>>n;
    int a[100000];
    for(int i=0; i<n; ++i)
    {

        cin>>a[i];
    }
    cout<<klarge(a, n);
    return 0;
}
