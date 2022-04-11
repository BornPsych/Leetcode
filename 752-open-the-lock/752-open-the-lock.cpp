class Solution {
public:
    map<string,vector<string>>adj;
    
    bool isValid(string i,string j){
        int c=0;
        for(int k=0;k<4;k++){
            if(i[k]!=j[k])c++;
        }
        
        if(c==1)return true;
        return false;
    }
    
    int openLock(vector<string>& dead, string target) {
        map<string,int>mp;
        for(auto &i:dead){
            mp[i]++;
        }
        
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    for(int l=0;l<10;l++){
                        string s="";
                        s+=(i+'0');s+=(j+'0');s+=(k+'0');s+=(l+'0');
                        if(!mp[s]){
                            string s1="";
                            s1+=((i+1)%10+'0');s1+=(j+'0');s1+=(k+'0');s1+=(l+'0');
                            string s2="";
                            s2+=((i+9)%10+'0');s2+=(j+'0');s2+=(k+'0');s2+=(l+'0');
                            string s3="";
                            s3+=(i+'0');s3+=((j+1)%10+'0');s3+=(k+'0');s3+=(l+'0');
                            string s4="";
                            s4+=(i+'0');s4+=((j+9)%10+'0');s4+=(k+'0');s4+=(l+'0');
                            string s5="";
                            s5+=(i+'0');s5+=(j+'0');s5+=((k+1)%10+'0');s5+=(l+'0');
                            string s6="";
                            s6+=(i+'0');s6+=(j+'0');s6+=((k+9)%10+'0');s6+=(l+'0');
                            string s7="";
                            s7+=(i+'0');s7+=(j+'0');s7+=(k+'0');s7+=((l+1)%10+'0');
                            string s8="";
                            s8+=(i+'0');s8+=(j+'0');s8+=(k+'0');s8+=((l+9)%10+'0');
                            adj[s] = {s1,s2,s3,s4,s5,s6,s7,s8};
                        }
                    }
                }
            }
        }
        
        map<string,int>visited;
        
        queue<string>q;
        q.push("0000");
        visited["0000"]=1;
        while(q.size()){
            string x = q.front();
            q.pop();
            for(auto i:adj[x]){
                if(!visited[i]){
                    visited[i] = visited[x]+1;
                    q.push(i);
                }
                
                if(i==target){
                    return visited[i]-1;
                }
            }
        }
        
        return -1;
        
        
       
        return 0;
    }
};