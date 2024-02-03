//Medium
//Array, 1D DP
//Time Complexity -> O(n*k)
//Space Complexity -> O(n) + O(k) auxiliary

// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

// Example 1:

// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]

class Solution {
public:
    int solve(int index, vector<int>& arr, int k, vector<int> &dp){
        int n = arr.size();
      
        if(index == n) return 0;
        if(dp[index] != -1) return dp[index];
      
        int len = 0;
        int maxi = INT_MIN;
        int finalAns = INT_MIN;

        for(int i=index; i< min(n, index+k); i++){   //n ya fir index+k mei se jo minimum ho, to make sure not out of bounds
            len++;                                   //len to keep track of partition length
            maxi = max(maxi, arr[i]);                //max element of that partition
          

            int sum = len * maxi + solve(i+1, arr, k, dp);    //len* maxi cuz changing all elements of that partition to largest element, then solve for next.
          //Basically, pehle ek element alag kiya, and baakio ka dekha max partition,
          //then do dekhe and aage walo ka partition aane diya through recursion
          //then teen.. upto k, and aage wala recursion sambhal raha hai

          
            finalAns = max(finalAns, sum);          //maximum sum wala permutation
        }
        return dp[index] = finalAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int index = 0;
        vector<int> dp(arr.size(), -1);  //cuz one variable change
        int ans = solve(index, arr, k, dp);
        return ans;
    }
};
