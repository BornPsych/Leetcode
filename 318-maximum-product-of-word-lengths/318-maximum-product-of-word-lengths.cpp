class Solution {
public:
    int maxProduct(vector<string>& words) {
        int mx=0;
        for(auto &i:words){
            map<char,int>mp;
             for(auto &j:i){mp[j]++;}
             
            for(auto &k:words){
                int f=0;  
                for(auto &l:k){
                     if(mp[l]){f=1;break;}
                 }
                if(f==0){
                    int y = i.length()*k.length();
                    mx=max(mx,y);}
             }
        }
        
        return mx;
    }
};