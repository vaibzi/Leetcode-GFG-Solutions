//Medium
//Topics -> String, Palindrome
//Time Complexity -> O(n2) ? 

// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.
// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

class Solution {
public:
    int expand(string s, int i, int j) {
        int cnt = 0;
        while(i>=0 && j<s.length() && s[i--] == s[j++])
            cnt++;
        return cnt;
    }
    int countSubstrings(string s) {
        int cnt = 0;
        for(int i=0; i<s.length(); i++) 
            cnt += expand(s,i,i) + expand(s,i,i+1);
        // here expand(s,i,i) return the count of the odd length palindromic substring. whose center is i
        // and expand(s,i,i+1)  return the count of the even length palindromic substring whose center is i & i+1
        return cnt;
    }
};
