class Solution {
public:
    int minDeletions(string s) {
        int a[26]={0};
        
        for(auto i:s){
            a[i-'a']++;
        }
        sort(a,a+26);
        
        reverse(a,a+26);
        int ans=0;
        for(int i=1;i<26;i++){
            if(a[i]==a[i-1] && a[i]!=0){
                ans++;
                a[i]--;
                i--;
                sort(a,a+26,greater<int>());
            }
        }
        
        return ans;
    }
};