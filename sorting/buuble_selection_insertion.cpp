//bubble sort
void bs(int *a, int n)
{
  for(int i=0; i<=n-2; ++i)
  {
    bool flag=true;
    for(int j=0; j<n-i-1; ++j)
    {
      if(a[j]>a[j+1])
      {
        flag=false;
        swap(a[j+1], a[j]);
      }
    }
    if(flag)
      break;
  }
}

//selection sort
void ss(int *a, int n)
{
  for(int i=0; i<n-1; ++i)
  {
    int min_ind=i;
    for(int j=i+1; j<n; ++j)
    {
      if(a[min_ind]>a[j])
        min_ind=j;
    }
    swap(a[i], a[min_ind]);
  }
}

//insertion sort
void is(int *a, int n)
{
  for(int i=1; i<n; ++i)
  {
    int j=i-1; int hole=i;
    while(j>=0 && a[hole]<a[j])
    {
      swap(a[hole], a[j]);
      --j;
      --hole;
    }
  }
}