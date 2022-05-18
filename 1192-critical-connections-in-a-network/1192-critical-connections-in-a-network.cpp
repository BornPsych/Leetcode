class Solution {
private:
    void findCriticalPaths(int node, int parent, int &timer,
                           vector<int> &tin, vector<int> &low, vector<bool> &vis,
                           vector<int> adj[], vector<vector<int>> &criticalPaths)
    {
        vis[node] = true;
        tin[node] = low[node] = timer++;
        
        for(int it : adj[node])
        {
            if(it == parent)
                continue;
            else if(!vis[it])
            {
                findCriticalPaths(it, node, timer, tin, low, vis, adj, criticalPaths);
                
                if(tin[node] < low[it])
                    criticalPaths.emplace_back(vector<int>({node, it}));
                
                low[node] = min(low[it], low[node]);
                
            }
            else
                low[node] = min(low[node], tin[it]);
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        if(n <= 1)  return vector<vector<int>>(0);
        
        vector<int> adj[n];
        for(vector<int> &con : connections)
        {
            adj[con[0]].emplace_back(con[1]);
            adj[con[1]].emplace_back(con[0]);
        }
        
        vector<bool> vis(n, false);
        vector<int> tin(n, -1), low(n, INT_MAX);
        
        int timer = 0;
        vector<vector<int>> criticalPaths;
        
		findCriticalPaths(0, -1, timer, tin, low, vis, adj, criticalPaths);
        
        return criticalPaths;
    }
};