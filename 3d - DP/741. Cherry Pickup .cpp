//Hard
//Topics -> 3D DP, Matrix
//Time Complexity -> O(n*m*m)
//Space Complexity -> O(n*m*m) DP + O(n) ASC

// You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

// 0 means the cell is empty, so you can pass through,
// 1 means the cell contains a cherry that you can pick up and pass through, or
// -1 means the cell contains a thorn that blocks your way.
// Return the maximum number of cherries you can collect by following the rules below:

// Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
// After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
// When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
// If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
 

// Example 1:


// Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
// Output: 5
// Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
// 4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
// Then, the player went left, up, up, left to return home, picking up one more cherry.
// The total number of cherries picked up is 5, and this is the maximum possible.


class Solution {
public:
    int dp[51][51][51];

    int func(int r1 , int c1 , int r2 , int n , vector<vector<int>> &grid )
    {
        int c2=r1+c1-r2;
        
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return INT_MIN;
        
        if(dp[r1][c1][r2]!=-1) return dp[r1][c1][r2];
        
        
        if(r1==n-1 && c1==n-1) return grid[r1][c1];
        
        
        int ans=grid[r1][c1];
        
        if(r1!=r2)  ans += grid[r2][c2];

        
        int temp= max(func(r1+1 , c1 , r2+1 , n , grid) , 
        func(r1 , c1+1 , r2 , n , grid));

        temp = max(temp , func(r1+1 , c1 , r2 , n, grid));
        temp = max(temp , func(r1 , c1+1 , r2+1 , n , grid));
        
        ans+=temp;
        
        return dp[r1][c1][r2]=ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp , -1 , sizeof(dp));
        int n=grid.size();
        return max(0 , func(0,0,0,n , grid));
    }
};


// **Intuitions **
// We have to take the cherries in such a way that it takes maximum of it , reach to (n-1 , n-1) , if possible and also make the taken cheeries as 0 .
// Now again we have to make one traversal from (n-1 , n-1) to (0 , 0) such that it can take the maximum of the remaining cheeries .
// Now trying this way will be make our life very hectic

// Think this questions as two persons are taking cheeries such a way that they following as maximum cheeries as they can take combinely and they cannot take the same cheeries
// i.e their sum of cheeries taken combinely is maximised , no need of maximising individual .

// Lets say (r1 , c1) coordinates of person1 , (r2 , c2) coordinates of person2 , 
// now as they both are intially at origin and they move max 1 step each time , we can say that distance of person1 from origin is equal to distance of person2 from origin

// i.e r1+c1=r2+c2
  
// Now take the current cheery of person 1 i.e grid[r1][c1] , if(r1!=r2) i.e they are not at same position , then take the cheery of person2 .

// There is 4 possibiltity of moving of (person1 , person2) 
// both moving 1 steps each at a time . i.e (right , right) , (right , down) , (down , right) , (down , down) . 

// Find out which path will give the maximum cheeries stores in temp variable and add it to ans variable.

// Edge cases : if any of one of two persons goes out of bounds or obstacles is present means this is not not possible ,
// return INT_MIN . if( person1 reaches the (n-1 , n-1)
// then return the grid[n-1][n-1] value ) both reaches simultaneously as r1 + c1=r2+c2 .
// if(already exists in 3-d dp matrix ) then return dp[r1][c1][r2] .
