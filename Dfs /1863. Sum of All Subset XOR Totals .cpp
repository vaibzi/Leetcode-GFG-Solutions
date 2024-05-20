//Easy
//Topics- Include Exclude in Subsets , Bitwise

// The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

// For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
// Given an array nums, return the sum of all XOR totals for every subset of nums. 

// Note: Subsets with the same elements should be counted multiple times.
// An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
    
private:
    int dfs(vector<int>& nums, int index, int currentXor) {
        // Base case: when all elements have been considered
        if (index == nums.size()) {
            return currentXor;
        }
        // Include nums[index] in the subset
        int include = dfs(nums, index + 1, currentXor ^ nums[index]);
        // Exclude nums[index] from the subset
        int exclude = dfs(nums, index + 1, currentXor);
        return include + exclude;
    }
};
