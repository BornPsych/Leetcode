int dp[1001][1001];

class Solution {
public:
    
    int solve(string &s1,string &s2,int n,int m){
        if(n==0 || m==0)return 0;
        
        if(dp[n][m]!=-1)return dp[n][m];
        
        if(s1[n-1]==s2[m-1]){
            return dp[n][m] = solve(s1,s2,n-1,m-1) +1;
        }else{
            return dp[n][m] = max(solve(s1,s2,n,m-1),solve(s1,s2,n-1,m));
        }
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,s1.length(),s2.length());
    }
};