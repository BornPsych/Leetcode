class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x]<0){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    
    void merge(int x,int y){
        x = find(x);
        y = find(y);
        
        if(x==y)return;
        parent[x] = y;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        for(int i=0;i<isConnected.size();i++){
            parent.push_back(-1);
        }
        
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1){
                    merge(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(parent[i]<0)count++;
        }
        
        return count;
    }
};