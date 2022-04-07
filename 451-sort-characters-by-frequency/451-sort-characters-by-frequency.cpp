class Solution {
public:
   
      
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        vector<pair<int,char>>v1;
        
        for(auto i:mp){
            v1.push_back({i.second,i.first});
        }
        
        sort(v1.begin(),v1.end(),greater<pair<int,char>>());
        string s1="";
        
        for(auto i:v1){
            while(i.first--){
                s1+=i.second;
            }
        }
        
        return s1;
    }
};