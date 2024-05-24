//Medium
//TC- O(2^N) SC - O(N)

// You are given an array nums of positive integers and a positive integer k.

// A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.
// Return the number of non-empty beautiful subsets of the array nums.
// A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

// Example 1:

// Input: nums = [2,4,6], k = 2
// Output: 4
// Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
// It can be proved that there are only 4 beautiful subsets in the array [2,4,6].

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        count = 0;
        explore(nums, k, 0);
        return count - 1; // Subtract 1 to exclude the empty subset
    }

private:
    int count;
    unordered_map<int, int> visited;

    void explore(vector<int>& nums, int k, int index) {
        if (index == nums.size()) {
            count++;
            return;
        }

        int num = nums[index];

        if (visited.find(num - k) == visited.end() &&
            visited.find(num + k) == visited.end()) {
            visited[num]++;
            explore(nums, k, index + 1);
            visited[num]--;
            if (visited[num] == 0) {
                visited.erase(num);
            }
        }

        explore(nums, k, index + 1);
    }
};
