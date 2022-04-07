class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        
        if(nums.size()<3)return v;
        for(int i=0;i<nums.size()-2;i++){
            int st=i+1,en=nums.size()-1;
            
            while(st<en){
                int x1 = nums[st],x2 =nums[en];
                if(nums[i]+x1+x2 == 0){
                    v.push_back({nums[i],x1,x2});
                    while(st<en && nums[st]==nums[st+1])st++;
                    while(st<en && nums[en]==nums[en-1])en--;
                    st++;en--;
                }else if(nums[i]+x1+x2<0){
                    st++;
                }else{
                    en--;
                }
                
                
            }
            
            while(i<nums.size()-1 && (nums[i]==nums[i+1])){
                i++;
            }
        }
        
        return v;
    }
};