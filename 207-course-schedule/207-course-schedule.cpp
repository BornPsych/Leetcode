class Solution {
public:
    vector<int>adj[100005];
    vector<bool>vis;
    vector<bool>stack;
    
    bool isCycle(int i){
        vis[i]=1;
        stack[i]=1;
        for(auto j:adj[i]){
            if(!vis[j]){
                 if(!isCycle(j))return false;}
            else if(stack[j]){
                
                return false;}
        }
        
        stack[i]=0;
        return true;
    }
    
    bool canFinish(int num, vector<vector<int>>& pre) {
        for(auto i:pre){
            adj[i[0]].push_back(i[1]);
        }
        for(int i=0;i<=num;i++){
            stack.push_back(0);
            vis.push_back(0);
        }
        
        for(int i=0;i<=num;i++){
            int y = true;
            if(!vis[i])y=isCycle(i);
            if(!y)return false;
        }
        
        return true;
    }
};