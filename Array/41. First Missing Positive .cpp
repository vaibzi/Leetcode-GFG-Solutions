//Hard
//Tc - O(n) SC-O(1)

// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

// Example 2:
// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.

  
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        auto it = unique(nums.begin(), nums.end());
        //removed all duplicates(cuz sorted first)

        nums.resize(distance(nums.begin(), it));
        //removed undefined/black spaces that were created

        int i=0;
        for(; i<nums.size();i++){
            if(nums[i]>0){
                break;
            }
        }
        //reached positive element
 
        int n=1;
        for(; i<nums.size(); i++){
            if(nums[i]!=n){
                break;
            }
            n++;
        }
        return n;
    }
};
