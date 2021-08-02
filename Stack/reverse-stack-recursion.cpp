Reverse a Stack using Recursion. Do not use any extra stack.

Input Format
First line contains an integer N (size of the stack).
Next N lines follow each containing an integer to be stored in the stack where the last integer is at the top of the stack.

Constraints
1 <= N <= 10^4

Output Format
Output the values of the reversed stack with each value in one line each.

Sample Input
3
3
2
1
Sample Output
3
2
1
Explanation
Original Stack = [ 3 , 2 , 1 ] <-TOP
Reverse Stack = [ 1 , 2 , 3 ] <-TOP

----------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int>&s, int x)
{
	if(s.empty())
		s.push(x);
	else
	{
		int t= s.top();
		s.pop();
		insert_at_bottom(s, x);
		s.push(t);
	}
}

void rev(stack<int>&s)
{
	if(s.empty())
		return ;
	int x= s.top();
	s.pop();
	rev(s);
	insert_at_bottom(s, x);
}

int main()
{
	stack<int>s;
	int n;
	cin>>n;
	int x;
	for(int i=0; i<n; ++i)
	{
		cin>>x;
		s.push(x);
	}
    rev(s);
	while(!s.empty())
	{
		cout<<s.top()<<'\n';
		s.pop();
	}
	return 0;
}