class Solution {
public:
    vector<int> adj[305];
    int vis[305];

    bool similar(string s1,string s2){
        int count=0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                count++;
                if(count>2){
                    return false;
                }
            }
        }

        return true;
    }

    void dfs(int i){
        vis[i]=1;
        for(auto u: adj[i]){
            if(!vis[u]){
                dfs(u);
            }
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int ans=0;
        int n= strs.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(similar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i);
                ans++;
            }
        }
        return ans;    
    }
};