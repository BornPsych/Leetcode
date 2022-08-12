class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0,ans=-1e9;
        for(auto i:nums)
        {
            curr+=i;
            if(curr>ans)ans=curr;
            
            if(curr<0)curr=0;
        }
        return ans;
    }
};