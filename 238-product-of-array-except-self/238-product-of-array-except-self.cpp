class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        int a[n],b[n];
        a[0]=nums[0];
        b[n-1]=nums.back();
        for(int i=1;i<n;i++){
            a[i] = nums[i]*a[i-1];
        }
        
        for(int i=n-2;i>=0;i--){
            b[i] = nums[i]*b[i+1];
        }
        
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(i==0){
                ans.push_back(b[i+1]);
            }else if(i==n-1){
                ans.push_back(a[i-1]);
            }else{
                ans.push_back(b[i+1]*a[i-1]);
            }
        }
        
        return ans;
    }
};