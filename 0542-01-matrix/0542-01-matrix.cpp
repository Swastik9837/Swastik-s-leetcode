// class Solution {
// public:
//    //Function to find the distance of nearest 1 in the grid for each cell.
// 	 vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
// 	{
// 	    int n = mat.size(); 
// 	    int m = mat[0].size(); 
// 	    // visited and distance matrix
// 	    vector<vector<int>> vis(n, vector<int>(m, 0)); 
// 	    vector<vector<int>> dist(n, vector<int>(m, 0)); 
// 	    // <coordinates, steps>
// 	    queue<pair<pair<int,int>, int>> q; 
// 	    // traverse the matrix
// 	    for(int i = 0;i<n;i++) {
// 	        for(int j = 0;j<m;j++) {
// 	            // start BFS if cell contains 1
// 	            if(mat[i][j] == 0) {
// 	                q.push({{i,j}, 1}); 
// 	                vis[i][j] = 1; 
// 	            }
// 	            else {
// 	                // mark unvisited 
// 	                vis[i][j] = 0; 
// 	            }
// 	        }
// 	    }
	    
// 	    int delrow[] = {-1, 0, +1, 0}; 
// 	    int delcol[] = {0, +1, 0, -1}; 
	    
// 	    // traverse till queue becomes empty
// 	    while(!q.empty()) {
// 	        int row = q.front().first.first; 
// 	        int col = q.front().first.second; 
// 	        int steps = q.front().second; 
// 	        q.pop(); 
// 	        dist[row][col] = steps; 
// 	        // for all 4 neighbours
// 	        for(int i = 0;i<4;i++) {
// 	            int nrow = row + delrow[i]; 
// 	            int ncol = col + delcol[i]; 
// 	            // check for valid unvisited cell
// 	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
// 	            && vis[nrow][ncol] 
//                    == 0) {
// 	                vis[nrow][ncol] = 1; 
// 	                q.push({{nrow, ncol}, steps+1});  
// 	            }
// 	        }
// 	    }
// 	    // return distance matrix
// 	    return dist; 
// 	}
// };

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({ i, j }); //Put all 0s in the queue.
                }
            }
        }

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
                if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                    if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                        dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                        q.push({ new_r, new_c });
                    }
                }
            }
        }
        return dist;
    }
};





    