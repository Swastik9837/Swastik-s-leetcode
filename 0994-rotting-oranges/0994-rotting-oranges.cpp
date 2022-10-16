// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//        // {{row,col},time} q;
//         queue<pair<pair<int,int>,int>> q;
//         int vis[n][m];
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(grid[i][j] == 2) //that mean the orange is rotten
//                 {
//                     q.push({{i,j},0});  //then take this orange row,col and time 0 sec 
//                     vis[i][j]=2; // or apne visited matrix mai bhi mark krdia ki vo rotten hai
//                 }
//             }
//             else{
//                 vis[i][j]=0;
//             }
//         }
        
//         int time=0;
//         int dRow[] = {-1,0,+1,0};
//         int dCol[] = {0,1,0,-1};
//         while(!q.empty())
//         {
//             int r=q.front().first.first(); // row 
//             int c = q.front().first.secont(); //col
//             int t=q.front().second();//time
//             time=max(time,t)
//             q.pop();
//             for(int i=0;i<=4;i++)
//             {
//                 int nrow= r + drow[i];   //nrow=neighbouring row
//                 int ncol= c+ dcol[i];    //ncol=neighbouring col
//                 if(nrow>=0 && nrow<n && ncol >=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol] == 1)
//                 {
//                     q.push({{nrow, ncol},t+1});
//                     vis[nrow][ncol]=1;
//                 }
//             }
            
             
//         }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(vis[i][j]!=2 && grid[i][j] == 1){
//                     return -1;
//                 }
//             }
//         }
//         return time;
        
        
        
//     }
// };

class Solution {
  public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector < vector < int >> & grid) {
      // figure out the grid size
      int n = grid.size();
      int m = grid[0].size();

      // store {{row, column}, time}
      queue < pair < pair < int, int > , int >> q;
      int vis[n][m];
      int cntFresh = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          // if cell contains rotten orange
          if (grid[i][j] == 2) {
            q.push({{i, j}, 0}); 
            // mark as visited (rotten) in visited array
            vis[i][j] = 2;
          }
          // if not rotten
          else {
            vis[i][j] = 0;
          }
          // count fresh oranges
          if (grid[i][j] == 1) cntFresh++;
        }
      }

      int tm = 0;
      // delta row and delta column
      int drow[] = {-1, 0, +1, 0};
      int dcol[] = {0, 1, 0, -1}; 
      int cnt = 0;

      // bfs traversal (until the queue becomes empty)
      while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        // exactly 4 neighbours 
        for (int i = 0; i < 4; i++) {
          // neighbouring row and column
          int nrow = r + drow[i];
          int ncol = c + dcol[i];
          // check for valid cell and 
          // then for unvisited fresh orange
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
            // push in queue with timer increased
             q.push({{nrow, ncol}, t + 1}); 
            // mark as rotten
            vis[nrow][ncol] = 2;
            cnt++;
          }
        }
      }

      // if all oranges are not rotten
      if (cnt != cntFresh) return -1;

      return tm;

    }
};