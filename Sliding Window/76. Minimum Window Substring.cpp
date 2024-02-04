//Hard
//String, Map, Sliding Window
//Time Complexity ->
//Space Complexity ->
//Companies - Airbnb

// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.


// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

class Solution {
public:
   string minWindow(string s, string t) {
        if(t==""){
            return "";
        }

        //Map elements for string t
        unordered_map<char,int> um;
        for(int i=0;i<t.length();i++){
            um[t[i]]++;
        }

        //need these many matches for valid substring
        int need = um.size();

        //Map for elements of current window
        unordered_map <char,int> window;

        int have = 0 ; //how many matches till now

        int minLen = INT_MAX;
        int min_pos = -1;

        int i = 0; // start index of the window.
        int j = 0; //end index of the window.
        char c;
        string ans="";

        while(j < s.length()){
            c = s[j];
            window[c]++;
            
            //present in both maps & same no. of occurrence
            if(um.find(c)!=um.end() && window[c]==um[c]) 
                have++;
            
            while(have == need){
                if(j-i+1 < minLen){ //j-i+1 is the window size
                    minLen = j-i+1;
                    min_pos = i;
                }

                // Remove unncessary characters from the 
                //front of the sliding window.
                window[s[i]]--;

                if (um.find(s[i]) != um.end() && window[s[i]] < um[s[i]])
                    have--;
                // Slide the window to the right.
                i++;
            }
            j++;
        }

        if(minLen<INT_MAX)
            ans = s.substr(min_pos,minLen); 
            //substring starting from min_pos of length minLen
            
        return ans;
    }
};
