#include<bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n) {
    stack<long long>s;
    vector<long long>ans;
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && arr[i] >= s.top())s.pop();
        if (s.empty()) ans.push_back(-1);
        else ans.push_back(s.top());
        s.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<long long>v;
    long long  x;
    for(int i=0; i<n; ++i)
    {
        cin>>x;
        v.push_back(x);
    }
    vector<long long> ans = nextLargerElement(v, n);
    for(auto x:ans)
        cout<<x<<' ';
}