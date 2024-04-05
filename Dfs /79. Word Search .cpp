//Medium

//Time complexity: 0(N * M * 4^k)
//Space complexity: O(1)

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Example 1:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
class Solution {
public:
    bool dfs(int i,int j,int count,vector<vector<char>>& board,string word)
    {
        // if we have found the whole string then count will become 
        //(word.length()==count) so return true
        
        if(word.length()==count) return true;
        
        // check for boundary                                  
        // curr char is not same with word char
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[count])
            return false;
        
        
        
        char temp = board[i][j];                    // curr char
        board[i][j] = ' ';                          // mark as visited
        
        
        // up , down , left , right (possible moves)
        bool ans = dfs(i-1,j,count+1,board,word) || 
                   dfs(i+1,j,count+1,board,word) ||
                   dfs(i,j-1,count+1,board,word) ||
                   dfs(i,j+1,count+1,board,word);
        
        board[i][j] = temp;                         
        // make board as it is for the upcoming calls

        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        int n = board.size();                   // rows
        int m = board[0].size();                // cols
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0] && dfs(i,j,0,board,word))  
                // whenever we found first letter of word start searching from there
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
