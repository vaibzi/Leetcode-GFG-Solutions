//Medium
//Topics -> Subarray, Prefix Sum, Map
// TC- > O(N), SC-> O(N)

// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

// Example 2:

// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.


// Approach
// Initialize a hash map to store prefix sums along with their indices.
// Initialize variables for sum, maximum subarray length, and iterate through the input array.
// For each element in the array, update the sum according to the element (decrement by 1 for 0, increment by 1 for 1).
// If the sum becomes zero at any index, update the maximum length to the current index plus one.
// If the sum is encountered again (which means there is a subarray with equal 0s and 1s between the previous occurrence and the current index), update the maximum length if the current subarray length is greater than the previously stored maximum length.
// Return the maximum subarray length.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();

        int sum = 0;
        int subArrayLength = 0;

        for(int i=0; i<n; i++){
            sum += nums[i]==0 ? -1 : 1;

            if(sum==0) subArrayLength = i+1;
            
            else if (m.find(sum) != m.end())
            subArrayLength = max(subArrayLength, i-m[sum]);

            else m[sum] = i;
        }
        return subArrayLength;
    }
};
