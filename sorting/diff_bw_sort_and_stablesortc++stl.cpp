//stable_sort(a, a+n); sorts the array with stability meaning the order of equal elements is preserved even after sorting
//sort(a, a+n); sorts the array but doesn't care about stability.
//so while sorting an array of structures/objects, stable_sort() is a preferable choice over sort() 

//note:
//when comparator functions are declared inside a class, make sure to declare them as static;
static bool compare(joda a, joda b)
{
    return a.abs_diff<b.abs_diff;
} 
++++++++++++++++++++++++++++++++------------------------++++++++++++++-----------------------------

Given an array of N elements and a number K. The task is to arrange array elements according to the absolute difference with K, i. e., element having minimum difference comes first and so on.
Note : If two or more elements are at equal distance arrange them in same sequence as in the given array.
 

Example 1:

Input: N = 5, K = 7
arr[] = {10, 5, 3, 9, 2}
Output: 5 9 10 3 2
Explanation: Sorting the numbers accoding to 
the absolute difference with 7, we have 
array elements as 5, 9, 10, 3, 2.

++++++++++++++++++++++++++++++++++++++++++++++++++------------------------------------------------------+++++++++++++++++++++
class solve{
public:
struct joda
{
    int ele;
    int abs_diff;
};

static bool compare(joda a, joda b)
{
    return a.abs_diff<b.abs_diff;
}

void sortABS(int a[],int n, int k)
{
    joda arr[n];
    for(int i=0; i<n; ++i)
    {
        arr[i].ele=a[i];
        arr[i].abs_diff=abs(a[i]-k);
    }
    stable_sort(arr, arr+n, compare);//to maintain stability 
    for(int i=0; i<n; ++i)a[i]=arr[i].ele;
}
};