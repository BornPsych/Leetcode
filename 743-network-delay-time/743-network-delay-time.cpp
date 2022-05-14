class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,int>>q;
        vector<int>dp(n+1,INT_MAX);
        q.push({k,0});
        dp[k]=0;
        vector<int>vis(n+1,false);
        while(!q.empty()){
            auto tmp=q.front();
            q.pop();
            int x=tmp.first;
            int t=tmp.second;
            for(auto it:adj[x]){
                if(dp[it[0]]>t+it[1]){
                    dp[it[0]]=t+it[1];
                    q.push({it[0],dp[it[0]]});    
                }
                
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dp[i]==INT_MAX)return -1;
            ans=max(ans,dp[i]);
        }
        if(dp[n]==INT_MAX)return -1;
        return ans;
    }
};