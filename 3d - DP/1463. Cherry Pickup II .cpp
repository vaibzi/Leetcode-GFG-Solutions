//Hard
//Time Complexity -> O(n * m * m) * 9
// (in recursion it was (3^n * 3^n)
//Space Complexity -> O(n*m*m) DP Array + O(N) ASC

//Topics -> 3D DP, Matrix, Grid

// You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

// You have two robots that can collect cherries for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.
 

// Example 1:


// Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
// Output: 24
// Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
// Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
// Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
// Total of cherries: 12 + 12 = 24.



class Solution {
public:
    int solve(int i, int j1, int j2, int r, int c, 
    vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){

        if(j1<0 || j2<0 || j1>=c || j2>=c) return -1e8;

        if(i == r-1){
            if(j1 == j2) return grid[i][j1]; //last row mei same pe aa gaye
            else return grid[i][j1] + grid[i][j2]; 
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e8;

        for(int dj1 = -1; dj1 <= 1 ; dj1++){ //cuz these three routes possible for 1st robot
            for(int dj2 = -1; dj2 <= 1 ; dj2++){ //for second robot
              //READ dj as delta j

                int value = 0;

                if(j1==j2) value = grid[i][j1]; //any one of them will take that
                else value = grid[i][j1] + grid[i][j2]; //add cuz different cells

                value += solve(i+1, j1+dj1, j2+dj2, r, c, grid, dp); //row increase, column increase/decrease acc to delta
                maxi = max(maxi, value); //maximum wala permutation saare delta ka aa jayega eventually
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<vector<int>>>dp
        (r, vector<vector<int>>(c, vector<int>(c, -1)));

        return solve(0, 0, c-1, r, c, grid, dp);
      // i = 0th row
      // j1 = 0 
      // j2 = c-1
    }
};
