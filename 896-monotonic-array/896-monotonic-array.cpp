class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int c1=0,c2=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>=0)c1++;
            
            if(nums[i]-nums[i-1]<=0)c2++;
        }
        
        if(c1==nums.size()-1 || c2==nums.size()-1)return true;
        else return false;
    }
};