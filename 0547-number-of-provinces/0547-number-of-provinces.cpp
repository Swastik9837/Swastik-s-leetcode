class Solution {
   private:
   void dfs(int node,vector<int>& visited,vector<int> adjList[])
    {
       
        for(auto it: adjList[node])
        {
            if(!visited[it])
            {
                visited[it]=1;
                dfs(it,visited,adjList);
            }
        }
    }
    public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size();
        vector<int> visited(n,0);
        vector<int> adjList[n];
		
      
		
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 and i!=j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i,visited,adjList);
            }
        }
        
        return count;
    }
};