class Solution {
public:
    bool check(string s1,string s2){
        int count=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i])count++;
        }
        
        if(count==1)return true;
        else return false;
    }
    
    int ladderLength(string begin, string end, vector<string>& word) {
        map<string,vector<string>>adj;
        map<string,int>vis;
        
        for(auto &i:word){
            if(check(begin,i)){
                adj[begin].push_back(i);
            }
        }
        
        for(int i=0;i<word.size();i++){
            for(int j=i+1;j<word.size();j++){
                if(check(word[i],word[j])){
                adj[word[i]].push_back(word[j]);
                adj[word[j]].push_back(word[i]);
               }
            }
        }
        
        queue<string>q;
        q.push(begin);
        vis[begin]=1;
        
        while(q.size()){
            string s1 = q.front();
            q.pop();
            
            for(auto &i:adj[s1]){
                if(!vis[i]){
                    vis[i] = vis[s1]+1;
                    q.push(i);
                    
                    if(i==end){
                        return vis[i];
                    }
                }
            }
            
        }
        
        return 0;
    }
};