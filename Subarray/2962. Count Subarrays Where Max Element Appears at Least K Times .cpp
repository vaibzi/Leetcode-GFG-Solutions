//Medium
// TC : O(N) , SC : O(1)
// Approach : Sliding Window

// You are given an integer array nums and a positive integer k.
// Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
// A subarray is a contiguous sequence of elements within an array.

// Example 1:

// Input: nums = [1,3,2,3,3], k = 2
// Output: 6
// Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int left = 0, right = 0;
        int n = nums.size();

        long long ans = 0;

        int max = *max_element(nums.begin(), nums.end());

        while (right < n) {
            
            k -= (nums[right++] == max);
                
            while (k==0){
                k += (nums[left++] == max);
            }
           
            ans += left;
        }
        return ans;
    }
};
