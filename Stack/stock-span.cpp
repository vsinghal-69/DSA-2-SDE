#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int x;
	vector<int>v;
	for(int i=1; i<=n; ++i)
	{
		cin>>x;
		v.push_back(x);
	}
	stack<int>s;
	vector<int>ans;
	for(int i=0; i<n; ++i)
	{
		while(!s.empty() && v[s.top()]<=v[i])
			s.pop();
		if(s.empty())
			ans.push_back(i+1);
		else
			ans.push_back(i-s.top());
		s.push(i);
	}
	for(auto x:ans)
		cout<<x<<' ';
	return 0;
}