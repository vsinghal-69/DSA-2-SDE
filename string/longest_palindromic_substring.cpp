/*Given an string, return the longest palindrome substring.
If there are more than one substring of max length, then return the first one or the max substring with min index.

NOTE: solve it in quadratic time.

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"

*/


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++---------------------------------------------------------------------------++++++++++++++++++++-----------------------------------
//Efficient approach
//Time complexity: O(n*n)
//Auxiliary space : O(1)


 string longestPalindrome(string s) {
        int maxm=0,l,r,odd,even,t_max;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            odd=1;//odd counts the no of odd length substring if we consider centre of the palindrome at s[i]
            while(i-odd>=0 && i+odd<n && s[i-odd]==s[i+odd])
                odd++;
            even=0;//even counts the no of even length substring if we consider centre of the palindrome at s[i]
	    // for even length palindrome, we compare s[i] with s[i-1] to check if they are equal.
            while(i-even-1>=0 && i+even<n && s[i-even-1]==s[i+even])
                even++;
            int odd_pal_size=2*odd-1;//max length of the odd length palindrome considering middle index of palindrome is i
            int even_pal_size=2*even;//max length of the even length palindrome considering middle index of palindrome is i
            t_max=max(odd_pal_size, even_pal_size);
            if(t_max>maxm)
            {
                maxm=t_max;
                if(odd_pal_size > even_pal_size)
                {
                    l=i-(odd-1),r=i+(odd-1);
                }
                else if(odd_pal_size < even_pal_size)
                {
                    l=i-even,r=i+even-1;
                }
            }
        }
        string lps=s.substr(l,r-l+1);//returns the substring that starts from index l and whose length is equal to r-l+1
        return lps;
    }