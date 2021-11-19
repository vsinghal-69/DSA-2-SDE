// find the minimum subarray sum


//method 1 --> tricky

int min_sum1(int a[], int n)
{
  // multiply all the array elements by -1;
  for(int i=0; i<n; ++i)
  {
    a[i]*=-1;
  }

  // find the max subarray sum using kadane's algo;
  int msum=INT_MIN;
  int cs=0;
  for(int i=0; i<n; ++i)
  {
    cs+=a[i];
    msum=max(msum, cs);
    if(cs<0)
      cs=0;
  }

  //multiply max subarray sum by -1 to get minimum subarray sum
  return msum*-1;
}


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++______________________________--------------------------------++++++++++++++++++-------------------------------------------

//method 2

int min_sum2(int a[], int n)
{
  //simply use kadane's algo
  int minm=0;
  int cs=0;
  for(int i=0; i<n; ++i)
  {
    cs+=a[i];
    minm=min(minm, cs);
    if(cs>0)
      cs=0;
  }
  return minm;
}


---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//method 3

int min_sum3(int a[], int n)
{
  // by choosing minimum  value between previous (min sum + current element) and (current element) at every index
  int minm=0;
  int cs=0;
  for(int i=0; i<n; ++i)
  {
    cs=min(cs+a[i], a[i]);
    minm=min(minm, cs);
  }
  return minm;
}