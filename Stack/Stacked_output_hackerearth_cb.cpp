/*You are at a casino. There are N stacked cards on pile . Each card has a number written on it. Then there will be Q iterations. In ith iteration, you start picking up the cards in Ai-1th pile from the top one by one and check whether the number written on the card is divisible by the ith prime number. If the number is divisible, you stack that card on pile Bi. Otherwise, you stack that card on pile Ai. After Q iterations, cards can only be on pile B1, B2, B3, . . . BQ, AQ . Output numbers on these cards from top to bottom of each piles in order of B1, B2, B3, . . . BQ, AQ .

Input Format
First line contains N and Q. The next line contains N space separated integers representing the initial pile of cards i.e., A0. The leftmost value represents the bottom plate of the pile.

Constraints
N < 10^5
Q < 10^5
|Ai| < 10^9

Output Format
Output N lines, each line containing the number written on the card.

Sample Input
5 1
3 4 7 6 5
Sample Output
4
6
3
7
5
Explanation
Initially:

A0 = [3, 4, 7, 6, 5]<-TOP

After 1st iteration:

A0 = []<-TOP

A1 = [5, 7, 3]<-TOP

B1 = [6, 4]<-TOP

Now first print B1 from top to bottom then A1 from top to bottom.*/

Solution ---------------------------------------------------------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;
unsigned long long p[1000001];
int main()
{
	int n,q;
	cin>>n>>q;
	stack<int>s;
	int x;
	for(int i=1; i<=n; ++i)
	{
		cin>>x;
		s.push(x);
	}
	for(int i=0; i<1000001; ++i)p[i]=1;
	p[0]=p[1]=0;
	for(long long i=2; i*i<=1000001; ++i)
	{
		if(p[i])
		{
			for(long long j=2*i; j<=1000001; j+=i)
			{
				p[j]=0;
			}
		}
	}
	vector<int>pp;
	for(int i=2; i<=1000001; ++i)
	{
		if(p[i])
			pp.push_back(i);
	}
	queue<int>ans;
	for(int it=0; it<q; ++it)
	{
		stack<int>b;
		queue<int>a;
		while(!s.empty())
		{
			if(s.top()%pp[it]==0)
			{
				b.push(s.top());
			}
			else
			{
				a.push(s.top());
			}
			s.pop();
		}
		while(!a.empty())
		{
			s.push(a.front());
			a.pop();
		}
		while(!b.empty())
		{
			ans.push(b.top());
			b.pop();
		}
	}
	while(!s.empty())
	{
		ans.push(s.top());
		s.pop();
	}
	while(!ans.empty())
	{
		cout<<ans.front()<<'\n';
		ans.pop();
	}
	return 0;
}