int dp[202][202];
const int dir[] = { 0, 1, 0, -1, 0 };

struct Solution {
    
    int m, n;
    vector<vector<int>> a;
    
    int dfs(int i, int j) {
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = 1;
        
        for (int d = 0; d < 4; d++) {
            
            int ii = i + dir[d];
            int jj = j + dir[d+1];
            
            if (ii >= 0 && ii < m &&
                jj >= 0 && jj < n &&
                a[ii][jj] > a[i][j]) {
                
                ans = max(ans, 1 + dfs(ii, jj));
            }
        }
        
        return dp[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        a = move(matrix);
        n = a[0].size();
        m = a.size();
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i,j));
            }
        }
        
        return ans;
    }
};
