class Solution {
public:
    int countOne(string &s, int count=0){
        for(auto c:s) count += c=='1';
        return count;
    }
    
    int solve(vector<string>& strs, int m, int n, vector<vector<vector<int>>> &dp, int i){
        if(i==strs.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        //Pick
        int c1 = ones[i];
        int c0 = strs[i].size() - c1;
        int pick = 0;
        if(m>=c0 and n>=c1) pick = 1 + solve(strs, m - c0, n - c1, dp, i+1);
        
        //Skip
        int skip = solve(strs, m, n, dp, i+1);
        
        return dp[i][m][n] = max(pick, skip);
    }
    
    vector<int> ones;
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(auto &s:strs) ones.push_back(countOne(s));
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(strs, m, n, dp, 0);
    }
};