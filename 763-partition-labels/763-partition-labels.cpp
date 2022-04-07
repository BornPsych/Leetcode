class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]=i;
        }
        vector<int>v;
        int maxx=0,mx=0,j=0;
        for(int i=0;i<s.length();i++){
            maxx = max(maxx,mp[s[i]]);
            j++;
            if(i==maxx){
                v.push_back(j);
                j=0;
                }
        }
        
        return v;
    }
};