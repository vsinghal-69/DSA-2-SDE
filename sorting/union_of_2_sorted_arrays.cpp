Union of 2 sorted arrays.
_________________________________________________________________________________________________________________________________________________________________________

n = 5, arr1[] = {1, 2, 3, 4, 5}  
m = 3, arr2 [] = {1, 2, 3}
Output: 1 2 3 4 5
Explanation: Distinct elements including 
both the arrays are: 1 2 3 4 5.

n = 5, arr1[] = {2, 2, 3, 4, 5}  
m = 5, arr2[] = {1, 1, 2, 3, 4}
Output: 1 2 3 4 5
Explanation: Distinct elements including 
both the arrays are: 1 2 3 4 5.

n = 5, arr1[] = {1, 1, 1, 1, 1}
m = 5, arr2[] = {2, 2, 2, 2, 2}
Output: 1 2
Explanation: Distinct elements including 
both the arrays are: 1 2.

_____________________________________________________________________________________________________________________________________________________________________


//arr1,arr2 : the arrays are already sorted
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int>ans;
        int i=0, j=0;
        while(i<n || j<m)
        {
            if(i<n && j<m)
            {
                if(arr1[i]<=arr2[j])
                {
                    ans.push_back(arr1[i++]);
                }
                else
                {
                    ans.push_back(arr2[j++]);
                }
            }
            else if(i<n)
            {
                ans.push_back(arr1[i++]);
            }
            else if(j<m)
            {
                ans.push_back(arr2[j++]);
            }
            int te=ans.size();
            if(te)
            {
                while(i<n && ans[te-1]==arr1[i])
                {
                    ++i;
                }
                while(j<m && ans[te-1]==arr2[j])
                {
                    ++j;
                }
            }
        }
        return ans;
    }