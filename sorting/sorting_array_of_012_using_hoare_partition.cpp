
arr[] = {0, 2, 1, 2, 0}
Output: 0 0 1 2 2

arr[] = {0, 1, 0}
Output: 0 0 1
---------------------------+++++++++++++++++++++++++++++++++++++++++++++++----------------------------------------------------+++++++++++++++++++++++

//function implementing hoare's partition algo that takes a pivot element and returns the last index upto which all elements are smaller than pivot
int hoare(int *a, int l, int r, int pivot)
    {
        int i=l, j=r;
        while(1)
        {
            while(a[i]<pivot)++i;
            while(a[j]>=pivot)--j;
            if(i<j)
            {
                swap(a[i], a[j]);
            }
            else
            {
                return i-1;
            }
        }
    }
  
//function called by main function. 
    void segragate012(int a[], int n)
    {
        int last_0_index= hoare(a, 0, n-1, 1);
        if(last_0_index==-1)
            last_0_index=0;
        int last_1_index= hoare(a,last_0_index+1, n-1, 2);
    }