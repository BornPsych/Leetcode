class Solution {
public:
    int dp[201][20002];
    bool solve(vector<int>&nums,int sum,int n){
        if(sum==0)return true;
        if(n<=0 || sum<0)return false;
        
        if(dp[n][sum]!=-1)return dp[n][sum];
        
        if(sum>=nums[n-1]){
            return dp[n][sum] = (solve(nums,sum,n-1) || solve(nums,sum-nums[n-1],n-1));
        }else{
            return dp[n][sum] = solve(nums,sum,n-1);
        }
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &i:nums){sum+=i;}
        if(sum&1)return 0;
        memset(dp,-1,sizeof(dp));
        sum = sum/2;
        int n = nums.size();
        return solve(nums,sum,n);
    }
};