class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid[0].size();
        int n=grid.size();
        vector<int> ans(m,0);
        
        for(int i=0;i<m;i++)
        {
            ans[i]=BallDropCol(0,i,grid);
        }
        return ans;
    }
    
    int BallDropCol(int row, int col, vector<vector<int>>& grid)
    {
        int m=grid[0].size();
        int n=grid.size();
        //base case ie ball reached the last row
        if(row==n)return col;
        int nextColumn=col+grid[row][col];// to find the value of next column
        if(nextColumn<0 || nextColumn>grid[0].size()-1 || grid[row][col] != grid[row][nextColumn]){
            return -1;
        }
        return BallDropCol(row+1,nextColumn,grid);
    }
};