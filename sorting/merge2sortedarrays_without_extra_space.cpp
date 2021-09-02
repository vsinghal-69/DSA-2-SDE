//Given 2 sorted arrays, merge them without extra space.
//first array contains first n elements and second array contains next m elements
/* Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.
*/

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-----------------------------------------------------------------------------------------

//first approach: time complexity: O(n*m) where n and m are the sizes of the arrays.
                //space complexity : O(1)


void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i=0, j=0;
            while(i<n && j<m)
            {
                if(arr1[i]>=arr2[0])
                {
                    swap(arr1[i], arr2[0]);
                    ++i;
                    while(j<=m-2 && arr2[j]>arr2[j+1])
                    {
                        swap(arr2[j], arr2[j+1]);
                        ++j;
                    }
                    j=0;
                }
                else
                {
                    ++i;
                }
            }
        } 


+++++++++++++++++++++++++++++++++++++++++++++++++++++++++-------------------------------------------------++++++++++++++++++++++
//second approach : using gap method

