class Solution {
public:
    vector<vector<int>>adj;
    vector<int>visited;
    bool dfs(vector<int>& arr,int start){
        if(arr[start]==0)return true;
        
        visited[start]=1;
        for(auto i:adj[start]){
            if(!visited[i]){
                bool x = dfs(arr,i);
                if(x==true)return true;
            }
        }
    return false;
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            adj.push_back({});
            int x1 = i + arr[i];
            int x2 = i - arr[i];
            visited.push_back(0);
            if(x1>=0 && x1<n){
                adj[i].push_back(x1);
            }
            if(x2>=0 && x2<n){
                adj[i].push_back(x2);
            }
        }
        
        return dfs(arr,start);
    }
};