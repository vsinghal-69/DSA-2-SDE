quick sort using hoare's partition

______________________________________++++++++++++++++++++++++++++++++++++++++++++++++++++++++++_________________________________---------------------------

//hoare's partition to partition the array
//always first element is considered as the pivot element

 int partition (int arr[], int low, int high)
    {
       //implementing hore's partition where first element is considered as pivot
       int pivot=arr[low];
       int i=low, j=high;
       while(1)
       {
           while(arr[i]<pivot)++i;
           while(arr[j]>=pivot)--j;
           if(i<j)
             swap(arr[i], arr[j]);
           else
             return i-1;
       }
    }


//function for quicksort

void quickSort(int arr[], int low, int high)
    {
        if(low<high)
        {
            int p=partition(arr, low, high);
            p=p<low?low:p;
            quickSort(arr, low, p);
            quickSort(arr, p+1, high);
        }
    }