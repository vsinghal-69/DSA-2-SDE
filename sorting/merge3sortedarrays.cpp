Given three sorted arrays A, B and C of size N, M and P respectively. The task is to merge them into a single array which must be sorted in increasing order.

Example 1:

Input: 
N = 4, A[] = [1 2 3 4] 
M = 5, B[] = [1 2 3 4 5] 
P = 6, C[] = [1 2 3 4 5 6]
Output: 1 1 1 2 2 2 3 3 3 4 4 4 5 5 6
Explanation: Merging these three sorted 
arrays, we have: 
1 1 1 2 2 2 3 3 3 4 4 4 5 5 6.

++++++++++++++++++++++++++++++++++++++++++++++++++++--------------------------------------------

vector<int> merge(vector<int>&a, vector<int>&b)
  {
      vector<int>ans;
      int n1=a.size();
      int n2=b.size();
      int i=0, j=0;
      while(i<n1 && j<n2)
      {
          if(a[i]<=b[j])
          
          {
              ans.push_back(a[i]);
              ++i;
          }
          else
          {
              ans.push_back(b[j]);
              ++j;
          }
      }
      while(i<n1)
      
      {
          ans.push_back(a[i]);
              ++i;
      }
      
      while(j<n2)
      {
          ans.push_back(b[j]);
              ++j;
      }
      return ans;
  }
  
  
  
    // A, B, and C: input sorted arrays
    //Function to merge three sorted vectors or arrays 
    //into a single vector or array.
    vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C) 
    { 
        int n1=A.size();
        int n2=B.size();
        int n3=C.size();
        vector<int>ans;
        ans=merge(A, B);
       
        return merge(ans, C);
    } 