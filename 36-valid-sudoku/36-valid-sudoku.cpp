// class Solution
// {
//     public:

//         bool isSafe(int row, int col, vector<vector < char>> &board1, int val)
//         {
//             for (int i = 0; i < board1.size(); i++)
//             {
//                	//row check
//                 if (board1[row][i] == val)
//                     return false;
//                	//col check
//                 if (board1[i][col] == val)
//                     return false;
//                	//3 * 3 ka matrix check krna hai
//                 if (board1[3 *(row / 3) + i / 3][3 *(col / 3) + i % 3] == val)
//                     return false;
//             }
//             return true;
//         }

//     bool solve(vector<vector < char>> &board1)
//     {
//         int n = board1[0].size();
//         for (int row = 0; row < n; row++)
//         {
//             for (int col = 0; col < n; col++)
//             {
//                 if (board1[row][col] == '.')	//ky row empty hai?
//                 {
//                     for (int val = 1; val <= 9; val++)
//                     {
//                         if (isSafe(row, col, board1, val))
//                         {
//                             board1[row][col] = val;	// ek val hamne bhrdi baki recursion se bharwadi
//                            	//recursive call
//                             bool aggeSolutionPossible = solve(board1);
//                             if (aggeSolutionPossible)
//                             {
//                                 return true;
//                             }
//                             else
//                             {
//                                	//agr ans nhi aaya toh hame        backtrack krna hai    
//                                 board1[row][col] = '.';
//                             }
//                         }
//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }

//     bool isValidSudoku(vector<vector < char>> &board)
//     {

//        return solve(board);
//     }
// };

















class Solution {
public:
    bool issafe(int r, int c, vector<vector<char>>&board, char val){
        for(int i=0;i<9;i++){
            if(board[r][i]==val)
                return false;
            if(board[i][c]==val)
                return false;
            if(board[3*(r/3)+(i/3)][3*(c/3)+(i%3)]==val)
                return false;
        }
        return true;
    }
    bool check(vector<vector<char>>&board){
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(isdigit(board[r][c])){
                    char val=board[r][c];
                    board[r][c]='.';
                    if(!issafe(r,c,board,val))
                        return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return check(board);
    }
};