//Medium
//Topics -> Array, NEXT GREATER ELEMENT

// Given an array of integers temperatures represents the daily temperatures, 

// return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 

// If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temps) {
        std::vector<int> results(temps.size());
        std::stack<int> stack;
        
        for (int i = 0; i < temps.size(); i++) {
            while (!stack.empty() && temps[stack.top()] < temps[i]) {
                results[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }

        return results;
    }
};
