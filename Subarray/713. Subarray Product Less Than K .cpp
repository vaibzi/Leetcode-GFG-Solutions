//Medium
//
// Approach - > Sliding Window

// Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
// Example 1:

// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int left = 0, right = 0, product = 1, count = 0;

    int n = nums.size();
    if(k <= 1) return 0;
    
    while (right < n) {
      product *= nums[right];
      while (product >= k) product /= nums[left++];
      count += 1 + (right - left);
      right++;
    }
    return count;
  }
};
