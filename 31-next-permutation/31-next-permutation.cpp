class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x=-1,xswap=0,n=nums.size();
        
        for(int i=n-1;i>0;i--){
            if(nums[i]-nums[i-1]>0){
                x = i-1;break;
            }
        }
        
        if(x==-1){
            reverse(nums.begin(),nums.end());
        }else{
            int mn=1e9;
            for(int i=x+1;i<n;i++){
                if(nums[i]-nums[x]>0 && mn>=nums[i]-nums[x]){
                    mn = nums[i]-nums[x];
                    xswap= i;
                }
            }
            
            swap(nums[x],nums[xswap]);
            
            reverse(nums.begin()+x+1,nums.end());
        }
    }
};