class Solution {
public:
    long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<long>> dp(n,vector<long>(m,0));
        
        dp[n-1][m-1] = obstacleGrid[n-1][m-1]==1?0:1;
        
        for(int i=m-2;i>=0;i--)
        {
            dp[n-1][i] = obstacleGrid[n-1][i]==1?0:dp[n-1][i+1];
            
        }
 
        for(int i=n-2;i>=0;i--)
        {
            dp[i][m-1] = obstacleGrid[i][m-1]==1?0:dp[i+1][m-1];
            
        }
 
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                if(obstacleGrid[i][j]!=1)
                {
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
                else{
                    dp[i][j] = 0;
                }
                
            }
        }
        
        return dp[0][0];
        
    }
};