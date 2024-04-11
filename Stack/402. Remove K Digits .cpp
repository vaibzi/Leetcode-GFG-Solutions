//Medium
//TC- O(N) , SC - O(N)
// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;

        for(char c : num){
            // While there are remaining removals (k) and the stack is not empty and the current digit is smaller than the top of the stack
            while(k>0 && !s.empty() && c<s.top()){
                s.pop();
                k--;
            }
            s.push(c);
        }

        while(k>0 &&  !s.empty()){
            s.pop();
            k--;
        }

        // Construct the result string by popping digits from the stack
        string temp ="";

        while(!s.empty()){
            temp.push_back(s.top());
            s.pop();
        }

        // Reverse the result string to get the correct order
        reverse(temp.begin(), temp.end());

        // Remove leading zeros and construct the final result
        int m = temp.size();
        string result = "";
        int foundNonZero = 0;

        for(int i=0; i<m; i++){
            if(temp[i] == '0' && foundNonZero==0) continue;
            else{
                result.push_back(temp[i]);
                foundNonZero = 1;
            }
        }

        // If the result is empty, return "0"
        if(result.size()==0) result.push_back('0');

        return result;
    }
};
