You are given an balanced expression. You have to find if it contains duplicate parentheses or not. A set of parentheses are duplicate if same subexpression is surrounded by multiple parenthesis.

Input Format
First line contains integer t as number of test cases.
Next t lines contains one balanced expression each.

Constraints
1 < t < 100
1< expression < 100

Output Format
Print "Duplicate" if the expression has any redundancy. Else print "Not Duplicates".

Sample Input
2
(((a+(b))+(c+d)))
((a+(b))+(c+d))
Sample Output
Duplicate
Not Duplicates
Explanation
For 1st test case : The subexpression "a+(b)" is surrounded by two pairs of brackets.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

string isd(string st)
{
	stack<char>s;
	for(int i=0; i<st.length(); ++i)
	{
		if(st[i] == ')')
		{
			bool flag =true;
			while(s.top()!='(')
            {
                flag =false;
                s.pop();
            }
			if(flag)
			{
                return "Duplicate";
			}
			s.pop();
		}
		else
		{
			s.push(st[i]);
		}
	}
	return "Not Duplicates";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<isd(s)<<'\n';
	}
	return 0;
}