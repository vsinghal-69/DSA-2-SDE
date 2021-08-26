#include<bits/stdc++.h>
using namespace std;

//recursive implementation of gcd
/*int gcd(int a, int b)
{
    //a acts as dividend and b acts as divisor
    if(b==0)
        return a;
    return gcd(b, a%b);
}*/


// iterative implementation of gcd
/*int gcd(int a, int b)
{
    int divisor=a<=b?a:b;
    int dividend=a+b-divisor;
    while(divisor)
    {
        int temp=divisor;
        divisor=dividend%divisor;
        dividend=temp;
    }
    return dividend;
}*/

int main()
{
    int a, b;
    cin>>a>>b;
    cout<<__gcd(a,b);  // __gcd(a,b) is the inbuilt stl function to find greatest common divisor.
    return 0;
}
