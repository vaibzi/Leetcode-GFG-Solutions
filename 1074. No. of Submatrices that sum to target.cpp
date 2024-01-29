// Topics -> Matrix. Subarrays

// Given a matrix and a target, return the number of non-empty submatrices that sum to target.

// A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

// Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

// Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
// Output: 4
// Explanation: The four 1x1 submatrices that only contain 0.

class Solution {
public:
	//This func is from prob no 560 -> subarray sum (1 D)
    int subarraySum(vector<int>& nums, int k) {
        int count=0,sum=0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==k)
            {
                count++;
            }
            if(mp.find(sum-k)!=mp.end())
            {
             count+=mp[sum-k];  
            }
            mp[sum]++;
        }
        return count;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
       int count=0;
        for(int i=0; i<matrix.size(); i++){
			
            vector<int> sum(matrix[0].size(), 0);   //Starts afresh from each row.
		
            for(int j=i; j<matrix.size(); j++){
                for(int k=0; k<matrix[0].size(); k++){
			
                    sum[k] += matrix[j][k];
			//This sum is basically the current row, after summing uske upar wale elements into that cell in each column. 
			//So, uske upar wale saare permutations will covered in it
			
                }
                count += subarraySum(sum, target); //running subarray sum for that row, covers all permutations
            }
        }
       
    return count;
    }
};
