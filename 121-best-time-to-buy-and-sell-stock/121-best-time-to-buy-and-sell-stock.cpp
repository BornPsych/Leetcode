class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,n=prices.size();
        int val = prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(val<prices[i])val=prices[i];
            else ans = max(ans,val-prices[i]);
        }
        
        return ans;
    }
};