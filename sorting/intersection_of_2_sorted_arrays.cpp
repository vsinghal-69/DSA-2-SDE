intersection of 2 sorted arrays.

________________________________________________________________________________________

N = 4, arr1[] = {1, 2, 3, 4}  
M = 5, arr2 [] = {2, 4, 6, 7, 8}
Output: 2 4
Explanation: 2 and 4 are only common 
elements in both the arrays.

N = 5, arr1[] = {1, 2, 2, 3, 4}
M = 6, arr2[] = {2, 2, 4, 6, 7, 8}
Output: 2 4
Explanation: 2 and 4 are the only 
common elements.

N = 2, arr1[] = {1, 2}
M = 2, arr2[] = {3, 4}
Output: -1
Explanation: No common elements, then return a vector containing -1.

____________________________________________________________________________________________________________________

vector<int> printIntersection(int arr1[], int arr2[], int n, int m) 
    { 
        vector<int>ans;
        int i=0, j=0;
        while(i<n && j<m)
        {
            if(arr1[i]==arr2[j])
            {
                ans.push_back(arr1[i]);
                ++i, ++j;
            }
            else if(arr1[i]<arr2[j])
            {
                ++i;
            }
            else
            {
                ++j;
            }
            int ts=ans.size();
            if(ts)
            {
                while(i<n && ans[ts-1]==arr1[i])
                {
                    ++i;
                }
                while(j<m && ans[ts-1]==arr2[j])
                {
                    ++j;
                }
            }
        }
        if(ans.size())
        {
            return ans;
        }
        else
        {
            return vector<int>{-1};
        }
    }