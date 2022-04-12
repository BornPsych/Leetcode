class Solution {
public:
    vector<int>visited[1000003];
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans(n,0);
        
        for(auto &i:edges){
            ans[i[1]]++;
        }
        
        vector<int>final;
        for(int i=0;i<n;i++){
            if(!ans[i])final.push_back(i);
        }
        
        return final;
    }
};