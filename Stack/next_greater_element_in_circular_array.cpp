#include<bits/stdc++.h>
using namespace std;

//method 1:Circular array, tc=o(n^2), sc=o(n).

vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int>ans;
    int n = nums.size();
    if (n == 0)
        return ans;
    for (int i = 0; i < n; ++i)
    {
        int j = 1;
        for (; j < n; ++j)
        {
            if (nums[(i + j) % n] > nums[i])
            {
                ans.push_back(nums[(i + j) % n]);
                break;
            }
        }
        if (j == n)
            ans.push_back(-1);
    }
    return ans;
}


//method 2:using stack, tc=o(n), sc=o(n)
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int>ans(n, -1);
    if (n == 0)
        return ans;
    stack<int>s;
    for (int i = 2 * n - 1; i >= 0; --i)
    {
        while (!s.empty() && nums[i % n] >= nums[s.top()])s.pop();
        if (!s.empty())
            ans[i % n] = nums[s.top()];
        s.push(i % n);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int>v;
    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        v.push_back(x);
    }
    vector<int> ans = nextGreaterElements(v);
    for (auto x : ans)
        cout << x << ' ';
}