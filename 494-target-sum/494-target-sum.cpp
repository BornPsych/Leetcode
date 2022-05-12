class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0,n=nums.size() ;
        sum = accumulate(nums.begin(),nums.end(),sum);
        
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0 && j==0)dp[i][j]=1;
                else if(i==0)dp[i][j]=0;
                else if(j>=nums[i-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        target = abs(target);
        int x = (sum+target);
        if(x&1)return 0;
        else{
            x = x/2;
            if(x>sum)return 0;
            return dp[n][x];
        }
        return 0;
    }
};