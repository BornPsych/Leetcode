class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        map<int,int>mp2;
        for(int i=0;i<nums.size();i++){mp2[nums[i]]++;mp[nums[i]]=i;}
        
        for(int i=0;i<nums.size();i++){
            if(target-nums[i]==nums[i] && mp2[nums[i]]<2){
                continue;
            }else if(mp2[target-nums[i]]){
                return {i,mp[target-nums[i]]};
            }
        }
        return {0};
    }
};