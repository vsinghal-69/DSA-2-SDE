// given 2 big integers(integers that can not fit into unsigned long long int, i.e., it have more than 19 digits).
// big integers are input in the form of string like "23456789876543456745678987654578"
// add 2 big integers



#include<bits/stdc++.h>
using namespace std;  
 
int main()
{
  string s1, s2;
  cin>>s1>>s2;
  int m=s1.size(), n=s2.size();
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  string ans="";
  int carry=0, i=0, j=0;
  while(i<m || j<n)
  {
    int sum=0;
    sum+=carry;
    if(i<m)
    {
      sum+=s1[i]-'0';
      ++i;
    }
    if(j<n)
    {
      sum+=s2[j]-'0';
      ++j;
    }
    ans+=char(sum%10+'0');
    carry=sum/10;
  }
  if(carry)
    ans+=char(carry+'0');
  reverse(ans.begin(), ans.end());
  cout<<ans;
  return 0;
}