class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        int dp[n+1][amt+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amt;j++){
                if(i==0 && j==0)dp[i][j]=INT_MAX-1;
                else if(i==0)dp[i][j]=INT_MAX-1;
                else if(j==0)dp[i][j]=0;
                else if(i==1){
                    if(j%coins[i-1])dp[i][j]=INT_MAX-1;
                    else dp[i][j]=j/coins[i-1];
                }
                else if(j>=coins[i-1]){
                    dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        if(dp[n][amt]==INT_MAX || dp[n][amt]==INT_MAX-1)return -1;
        return dp[n][amt];
        
    }
};