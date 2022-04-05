class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        int f=0,ans=0;
        for(auto i:mp){
            ans+=(i.second)/2;
            if(i.second%2)f=1;
        }
        
        if(f)return ans*2+1;
        else return ans*2;
    }
};