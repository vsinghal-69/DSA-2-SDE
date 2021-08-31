//these partition methods are used in quick sort.

//naive function to partition an array
//tc:O(1) && sc:O(1)
//mantains stability
//returns the index of the correct pos where pivot should be fitted
int np(int *a, int l, int r, int pivot_ind)
{
  int size=r-l+1;
  int ta[size];
  int ind=0;
  for(int i=l; i<=r; ++i)
  {
    if(a[i]<a[pivot_ind])
    {
      ta[ind++]=a[i];
    }
  }
  for(int i=l; i<=r; ++i)
  {
     if(a[i]==a[pivot_ind])
    {
      ta[ind++]=a[i];
    }
  }
  int res=l+ind-1;//res stores the index of the pivot in ta 
  for(int i=l; i<=r; ++i)
  {
    if(a[i]>a[pivot_ind])
    {
      ta[ind++]=a[i];
    }
  }
  for(auto x:ta)cout<<x<<' ';
    cout<<'\n';
  return res;
}

________________________________________________________________________________________________________

//lomuto partition algo
//not stable
//tc:O(n), sc:O(1)
//pivot element is always considered as the last element or element at index h
//returns the index of the pivot element where it has to be fitted
int lp_last_pivot(int *a, int l, int h)
{

  //pivot is the last element or the element at index h
  //i maintains the first index where the element greater than pivot was found.
  //every time an element less than pivot is found at index j, then it is swapped with max element at pos i and the value of i is incremented
  int i=l, j=l;
  for(; j<=h-1; ++j)
  {
    if(a[j] < a[h])
    {
      swap(a[i], a[j]);
      ++i;
    }
  }
  //at last swap the pivot element with i, i.e., the first element where element graeter than pivot exists.
  swap(a[i], a[h]);
  for(int i=l; i<=h; ++i)cout<<a[i]<<' ';
    cout<<'\n';
  return i;//i is the index where pivot element has been kept.
}

_______________________________________________________________________________________

//lomuto partition where pivot index is not the last index and it can be any index passed in the function
//just swap the last element with the pivot element and apply the standard lomuto partition algo
int lp_last_pivot(int *a, int l, int h, int pivot_index)
{
  swap(a[h], a[pivot_index]);
  int i=l, j=l;
  for(; j<=h-1; ++j)
  {
    if(a[j] < a[h])
    {
      swap(a[i], a[j]);
      ++i;
    }
  }
  //at last swap the pivot element with i, i.e., the first element where element graeter than pivot exists.
  swap(a[i], a[h]);
  for(int i=l; i<=h; ++i)cout<<a[i]<<' ';
    cout<<'\n';
  return i;//i is the index where pivot element has been kept.
}

______________________+++++++++++++++++++++++++++++++++++++++++++_______________________________________________


//hoare's partition
//this is the most effective partition method but in this method the pivot element is not placed at the correct position.
//not stable
//tc:O(n), sc:O(1)
//pivot is by default considered as the first element
int hoare_partition(int *a, int l, int r)
{
  int pivot=a[l];//assume element at index l is the pivot element
  //move i to right until a[i]<pivot. 
  //move j to the left until a[j]>=pivot
  //in hoare's partition, the pivot element or elements equal to pivot may be or may not be present at the correct position but all the elements in the left partition are smaller than pivot and all the elements in the right are greater than pivot
  int i=l, j=r;
  while(true)
  {
    while(a[i]<pivot)++i;
    while(a[j]>=pivot)--j;
    if(i<j)
    {
      swap(a[i], a[j]);
    }
    else
    {
      return i;//returning i bcz, i is the first index that points to the element greater than equal to pivot and all the elements from index [l, i-1] are smaller than pivot. so, i denotes the partition position

    }
  }
}
