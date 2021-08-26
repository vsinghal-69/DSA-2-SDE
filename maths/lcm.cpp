It is a mathematical property that:
2 integers a, b.. 
a*b = lcm(a, b) * gcd(a,b)

so, lcm(a,b) = (a*b)/gcd(a,b);

To avoid integer overflow fro (a*b)  we can do, --> a*(b/__gcd(a,b));
 
Here __gcd(a,b) is the inbuilt c++ stl function to find hcf.