//Medium
//Topics -> String, Map
//Time Complexity -> O(n)

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map <string, vector<string>> groups;

        for(string str : strs){
            string sortedStr = str;

            sort(sortedStr.begin(), sortedStr.end());  //Sort every element of given string
            groups[sortedStr].push_back(str);          //Input in Map, cuz anagram toh same ho jayega na sort hone ke baad

        }

        for(auto group : groups){
            ans.push_back(group.second);
        }
        return ans;


    }
};
