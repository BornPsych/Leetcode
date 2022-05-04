class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto i:nums){mp[i]++;}
        int ans=0;
        for(auto i:nums){
            int x = k-i;
            if(x==i && mp[i]>1){ans++;mp[i]-=2;cout<<'a';}
            else if(x!=i && mp[i]>0 && mp[x]>0){ans++; mp[i]--;mp[x]--;}
        }
        
        
        return ans;
    }
};