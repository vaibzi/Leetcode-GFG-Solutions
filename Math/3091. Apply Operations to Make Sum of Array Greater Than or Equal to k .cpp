//Medium
//TC -> O(N)

// You can perform any of the following operations on the array any number of times (possibly zero):

// Choose any element in the array and increase its value by 1.
// Duplicate any element in the array and add it to the end of the array.
// Return the minimum number of operations required to make the sum of elements of the final array greater than or equal to k.

// Example 1:

// Input: k = 11
// Output: 5

// Explanation:
// We can do the following operations on the array nums = [1]:
// Increase the element by 1 three times. The resulting array is nums = [4].
// Duplicate the element two times. The resulting array is nums = [4,4,4].
// The sum of the final array is 4 + 4 + 4 = 12 which is greater than or equal to k = 11.
// The total number of operations performed is 3 + 2 = 5.

class Solution {
public:
    int minOperations(int k) {
        int ans = INT_MAX;
        
        if(k==1) return 0;
        
        for(int i=1; i<=k/2; i++){          // i is the number from which we start multiplying , till i, just increment
            int temp = ceil((double)k/i);   //No. of times we have to multiply 
            int operations = temp-1 + i-1;  // -1 in both, cuz np.of operation toh 1 kam lagega na, try to visulaise

            //4+4+4 karne mei, temp = 3, but operation toh 2 hi lage
            //aise hi 1+1 = 2 karn mei, i=2, but operation = 1
          
            ans = min(operations, ans);
        }
        
        return ans;
        
    }
};
