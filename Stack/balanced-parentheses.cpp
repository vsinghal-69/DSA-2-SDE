#include<bits/stdc++.h>
using namespace std;

bool iob(char b)
{
	if(b=='(' || b=='{' || b=='[')
		return true;
	return false;
}

bool rp(char o, char c)
{
	if((o=='(' && c==')') || (o=='{' && c=='}') || (o=='[' && c==']'))
		return true;
	return false; 
}

int main()
{
	string s;
	cin>>s;
	string ans="Yes";
	stack<char>sc;
	for(int i=0; i<s.length(); ++i)
	{
		if(iob(s[i]))
			sc.push(s[i]);
		else
		{
			if(sc.empty() || !rp(sc.top(), s[i]))
			{
				ans="No";
				break;
			}
			sc.pop();
		}
	}
	if(!sc.empty())
		ans="No";
	cout<<ans;
	return 0;
}