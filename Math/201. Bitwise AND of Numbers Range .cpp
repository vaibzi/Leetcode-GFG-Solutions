//Medium
//TC -> O(1), SC -> O(1)
//Topic -> Bitwise Operations

// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
// Example 1:

// Input: left = 5, right = 7
// Output: 4

//see approach in png file
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int count = 0;

        while(left != right){
            left >>= 1;
            right >>= 1;
            count += 1;
        }

        return left <<= count;
    }
};
