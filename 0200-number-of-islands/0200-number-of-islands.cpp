class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
     int count=0;
        for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].size();j++)
                if(dfs(grid,i,j))
                count++;
        return count;
    }
    bool dfs(vector<vector<char>>&grid,int r,int c)
    {  
        
    if(r<0 || r==grid.size() || c<0 ||   c==grid[0].size())
            return false;
        if(grid[r][c]=='0')
            return false;
    
       grid[r][c]='0';
        // up
     dfs(grid,r-1,c);
        // down
        dfs(grid,r+1,c);
        // right
       dfs(grid,r,c+1);
        // left
       dfs(grid,r,c-1);
        return true;
    }
};