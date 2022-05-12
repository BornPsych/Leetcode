class Solution {
public:
    int dp[201][20002];
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &i:nums){sum+=i;}
        if(sum&1)return 0;
        memset(dp,-1,sizeof(dp));
        sum = sum/2;
        int n = nums.size();
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0)dp[i][j]=0;
                if(j==0)dp[i][j]=1;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j>=nums[i-1]){
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-nums[i-1]]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};