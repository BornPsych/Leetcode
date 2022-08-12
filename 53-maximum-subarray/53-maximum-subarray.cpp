class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0,ans=-1e9;
        for(auto i:nums)
        {
            curr+=i;
            curr=max(curr,i);
            ans=max(ans,curr);
        }
        return ans;
    }
};