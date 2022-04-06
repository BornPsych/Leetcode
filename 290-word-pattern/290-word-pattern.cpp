class Solution {
public:
    bool wordPattern(string p, string s) {
        string s1;
        vector<string>sv;
        for(const char i:s){
            if(i==' '){
                sv.push_back(s1);
                s1="";
            }else{
                s1+=i;
            }
        }sv.push_back(s1);
        map<char,string>mp;
        map<string,char>mp1;
        if(sv.size()!=p.length())return false;
        for(int i=0;i<p.size();i++){
            if(mp[p[i]]=="" && mp1[sv[i]]==0){
                mp[p[i]]=sv[i];
                mp1[sv[i]]=p[i];
            }else if(mp[p[i]]=="" && mp1[sv[i]]!=0){
                return false;
            }else if(mp[p[i]]!="" && mp1[sv[i]]==0){
                return false;
            }else if(mp[p[i]]!=sv[i]){
                return false;
            }
        }
        
        return true;
    }
};