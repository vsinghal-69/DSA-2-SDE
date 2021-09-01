//merging the intervals, if they overlap.
//an interval merges if the end point of one interval is equal to the start point of another interval.
//ex: [1, 6] , [6, 12]
//an interval merges if the start point of the interval having largest start point is smaller than equal to the end point of the interval having smallest start point
//ex: [1, 6], [3, 19]

+++++++++++++++++++++++++++++++++++++++++++++++++----------------------------------------------++++++++++++++++++++++++++++++++++++
//time complexity: O(n*logn)
//auxiliary space : O(1)
//algo:
//firstly sort the array of structures on the basis of the start point of the intervals/structures
//see the rest of teh algo into the code or refer gfg dsa course, sorting section


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-------------------------------------+++++++++++++++++++++++


#include<bits/stdc++.h>
using namespace std;

//structure defining the interval.
struct interval
{
    int start;//start point of the interval
    int khatm;//end point of the interval
};

//user defined comparator function based on which the c++ stl sort() function sorts the array of structures on the basis of their start point of interval in ascending order

bool compare(interval a, interval b)
{
    return a.start<b.start;
}

//function to check if 2 intervals overlap.
//no use of this fn in this question

bool do_overlap(interval a, interval b)
{
    if(a.start<b.start)
    {
        if(a.khatm >= b.start)
            return true;
    }
    else
    {
        if(a.start<=b.khatm)
            return true;
    }
    return false;
}

//function to merge the 2 intervals if they overlap
//no use of this fn too in this solution

interval merge_interval(interval a, interval b)
{
    interval res;
    res.start=min(a.start, b.start);
    res.khatm=max(a.khatm, b.khatm);
}

//function to solve this ques efficiently

int solve(interval *a, int n)
{
    int res=0;
    for(int i=1; i<n; ++i)
    {
        if(a[i].start<=a[res].khatm)
        {
            a[res].start=min(a[i].start, a[res].start);
            a[res].khatm=max(a[i].khatm, a[res].khatm);
            cout<<"merge ho gaya : "<<a[res].start<< ' '<<a[res].khatm<<'\n';
        }
        else
        {
            a[++res]=a[i];
        }
    }
    return res;
}


int main()
{
    int n;
    cin>>n;
    interval a[10000];
    for(int i=0; i<n; ++i)
    {
        cin>>a[i].start>>a[i].khatm;
    }

    sort(a, a+n, compare);
    int res=solve(a, n);

    //printing array of intervals after merging all the overlapping intervals

    for(int i=0; i<=res; ++i)
    {
        cout<<a[i].start<<' '<<a[i].khatm<<'\n';
    }
    return 0;
}

