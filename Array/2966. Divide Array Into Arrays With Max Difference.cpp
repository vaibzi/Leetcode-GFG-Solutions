//Medium
//Topics -> Array, 2D array, sort
// Time Complexity -> O(n)

// You are given an integer array nums of size n and a positive integer k.

// Divide the array into one or more arrays of size 3 satisfying the following conditions:

// Each element of nums should be in exactly one array.
// The difference between any two elements in one array is less than or equal to k.
// Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.


// Example 1:

// Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
// Output: [[1,1,3],[3,4,5],[7,8,9]]
// Explanation: We can divide the array into the following arrays: [1,1,3], [3,4,5] and [7,8,9].
// The difference between any two elements in each array is less than or equal to 2.
// Note that the order of elements is not important.

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> arr;
        vector<int> temp;
        if(n%3 != 0 || n==0) return arr;

        sort(nums.begin(), nums.end());

        temp.push_back(nums[0]);
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(count == 0){
                temp.push_back(nums[i]);
                count++;
                continue;
            } 

            if (count==1 && nums[i] - nums[i-1] <= k ){
                temp.push_back(nums[i]);
                count++;
            }

            else if(count==2 && nums[i]-nums[i-2] <= k){
                temp.push_back(nums[i]);
                count++;
            }

            else if(count==1 && nums[i] - nums[i-1] > k){
                arr.clear();
                break;
            }

            else if(count==2 && nums[i] - nums[i-2] > k){
                arr.clear();
                break;
            }

            if(count == 3){
                count=0;
                arr.push_back(temp);
                temp.clear();
            }
        }
        return arr;
    }
};
