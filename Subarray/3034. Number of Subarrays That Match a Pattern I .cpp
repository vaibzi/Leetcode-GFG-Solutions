//Medium
//Time Complexity -> O(n2)
//Topics -> Subarray

// You are given a 0-indexed integer array nums of size n, and a 0-indexed integer array pattern of size m consisting of integers -1, 0, and 1.

// A  subarray nums[i..j] of size m + 1 is said to match the pattern if the following conditions hold for each element pattern[k]:
// nums[i + k + 1] > nums[i + k] if pattern[k] == 1.
// nums[i + k + 1] == nums[i + k] if pattern[k] == 0.
// nums[i + k + 1] < nums[i + k] if pattern[k] == -1.
// Return the count of subarrays in nums that match the pattern.

// Example 1:

// Input: nums = [1,2,3,4,5,6], pattern = [1,1]
// Output: 4
// Explanation: The pattern [1,1] indicates that we are looking for strictly increasing subarrays of size 3. In the array nums, the subarrays [1,2,3], [2,3,4], [3,4,5], and [4,5,6] match this pattern.
// Hence, there are 4 subarrays in nums that match the pattern.

class Solution {
public:
    
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        
        int m = pattern.size();
        int count = 0;
        
        bool flag = true;
        
        for(int i = 0; i<n; i++){
            for(int k=0; k<m; k++){
                if(i+k+1 >= n){
                    flag=false;break;
                }
                if(pattern[k] == 1){
                    if(nums[i+k]<nums[i+k+1]) continue;
                    else flag=false;
                }
                else if(pattern[k] == 0){
                    if(nums[i+k]==nums[i+k+1]) continue;
                    else flag=false;
                }
                else if(pattern[k] == -1){
                    if(nums[i+k]>nums[i+k+1]) continue;
                    else flag=false;
                }
            }
            if(flag==true) count++;
            else flag=true;
        }
        return count;
    }
};
