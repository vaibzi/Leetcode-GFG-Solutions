//Medium
//TC- O(N)2

// You are given an m x n binary matrix grid.

// A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
// Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

// Return the highest possible score after making any number of moves (including zero moves).

//Appproach -
//1) If the first bit of a number is 0, flip that row
//2) now checking columuns from j=1 (cuz first bit toh karli), if no. of ones < no. of zeros in a column, flip that column

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        for (int r = 0; r < row; r++) {
            if (grid[r][0] == 0) {
                flipRow(grid, r);
            }
        }
        for (int c = 1; c < col; c++) {
            colOnes(grid, c);
        }
        int rowSum = 0;
        for (int r = 0; r < row; r++) {
            int currNum = 0;
            for (int c = 0; c < col; c++) {
                if (grid[r][col - 1 - c] == 1) {
                    currNum += (1 << c); //Multiplying by 2, cuz converting binary to decimal, and adding
                }
            }
            rowSum += currNum;
        }
        return rowSum;
    }
private:
    void colOnes(vector<vector<int>>& grid, int c) {
        int oneCnt = 0;
        for (int r = 0; r < grid.size(); r++) {
            if (grid[r][c] == 1) oneCnt++;
        }
        int zeroCnt = grid.size() - oneCnt;
        if (zeroCnt > oneCnt) flipCol(grid, c);
    }
    void flipRow(vector<vector<int>>& grid, int r) {
        for (int c = 0; c < grid[0].size(); c++) {
            grid[r][c] = (grid[r][c] == 1) ? 0 : 1;
        }
    }
    void flipCol(vector<vector<int>>& grid, int c) {
        for (int r = 0; r < grid.size(); r++) {
            grid[r][c] = (grid[r][c] == 1) ? 0 : 1;
        }
    }
};
