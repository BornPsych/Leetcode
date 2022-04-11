class Solution {
public:
    bool isValid(string s1,string s2){
        int count=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                count++;
            }
        }
        
        if(count==1)return true;
        else return false;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        map<string,vector<string>>adj;
        map<string,int>vis;

        
        for(auto i:bank){
                if(isValid(start,i)){
                    adj[start].push_back(i);
                }
        }

        for(auto i:bank){
            for(auto j:bank){
                if(isValid(i,j)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        queue<string>q;
        q.push(start);
        vis[start]=1;
        while(q.size()){
            string x = q.front();
            q.pop();
            for(auto i:adj[x]){
                if(!vis[i]){
                    vis[i] = vis[x]+1;
                    q.push(i);
                
                    
                    if(i==end){
                        return vis[i]-1;
                     }
                
                }
                
                
            }
        }
    
        return -1;
    }
};