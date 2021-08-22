Use binary search to compute floor of square root of an integer.
EX: for n=11, sqrt=3
    for n=9, sqrt=3

time-complexity: o(logn)
space-complexity: o(1)
__________________________________________________________________________________

int Solution::sqrt(int a) {
    int s=1, e=a;
    int ans;
    while(s<=e)
    {
        unsigned long long mid=s+(e-s)/2;
        unsigned long long sqt=mid*mid;
        if(sqt==a)
            return mid;
        else if(sqt>a)
            e=mid-1;
        else
        {
            s=mid+1;
            ans=mid;
        }
    }
    return ans;
}


___________________________________________________________________________________________

find sqare_root of a int no, n upto a given precision p.
_________________________________________________________________________________________________
//p denotes precision here

float bs(int n, int p)
{
  float cp=1;float ans=1;
  for(int i=0; i<=p; ++i)
  {
    while(ans*ans<=n)
    {
      ans+=cp;
    }
    ans-=cp;
    cp/=10;
  }
  return ans;
}