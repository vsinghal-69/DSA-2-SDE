
//function to divide a array into 2 sorted arrays then merge them
void merge(int *a, int l, int mid, int r)
{
  int size1=mid-l+1, size2=r-mid;
  int arr1[size1];
  int arr2[size2];
  int k=l;
  for(int i=0; i<size1; ++i)
  {
    arr1[i]=a[k++];
  }
  for(int i=0; i<size2; ++i)
  {
    arr2[i]=a[k++];
  }
  int i=0, j=0, z=l;
  while(i<size1 && j<size2)
  {
    if(arr1[i]<=arr2[j])
    {
      a[z++]=arr1[i++];
    }
    else
    {
      a[z++]=arr2[j++];
    }
  }
  while(i<size1)
  {
    a[z++]=arr1[i++];
  }
  while(j<size2)
  {
    a[z++]=arr2[j++];
  }
}

//merge sort 
void merge_sort(int *a, int l, int r)
{
  if(l<r)
  {
    int mid=l+(r-l)/2;
    merge_sort(a, l, mid);
    merge_sort(a, mid+1, r);
    merge(a, l, mid, r);
  }
}


int main()
{
  int a[10]{2,-2,90,8,34,43,32,23,1};
  int n=sizeof(a)/sizeof(a[0]);
  merge_sort(a, 0, n-1);
  for(int x:a)cout<<x<<' ';
  return 0;
}