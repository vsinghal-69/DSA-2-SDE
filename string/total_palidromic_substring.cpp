/*Given a string, return the count of total palindromic substrings in it in quadratic time.

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa". */

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//efficient approach
//Time complexity : O(n*n)
//Auxiliary space : O(1)


 int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        int odd, even;
        for(int i=0; i<n; ++i)
        {
            odd=1;//odd counts the no of odd length palindromic substrings considering s[i] as the centre of the palindromic substring
	    //since every character is a odd length(1) palindromic substring, so odd has been initialized to 1
            while(i-odd>=0 && i+odd<n && s[i-odd]==s[i+odd])
                ++odd;
            even=0;//even counts the no of even length palindromic substrings considering s[i] as the centre of the palindromic substrings
            while(i-even-1>=0 && i+even<n && s[i-even-1]==s[i+even])
                ++even;
            ans+=odd;
            ans+=even;
        }
        return ans;
    }