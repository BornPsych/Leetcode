class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        
        for(auto &i:strs){
            string s1 = i;
            sort(s1.begin(),s1.end());
            mp[s1].push_back(i);
        }
        
        vector<vector<string>>v;
        
        for(auto i:mp){
            v.push_back(i.second);
        }
        
        return v;
        
    }
};