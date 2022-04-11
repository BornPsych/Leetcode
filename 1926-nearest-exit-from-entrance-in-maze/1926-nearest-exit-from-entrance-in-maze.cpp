class Solution {
public:
    int ans = INT_MAX;
    void bfs(vector<vector<char>>& maze, vector<int>& en){
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>>vis(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i].push_back(0);
            }
        }
        
        queue<pair<int,int>>q;
        q.push({en[0],en[1]});
        vis[en[0]][en[1]]=1;
        
        int x1[4] = {1,0,-1,0};
        int y1[4] = {0,1,0,-1};
        
        while(q.size()){
            auto x = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int x2 = x.first  + x1[i];
                int y2 = x.second + y1[i];
                
                if(x2>=0 && y2>=0 && x2<n && y2<m){
                    if(maze[x2][y2]=='.' && !vis[x2][y2]){
                        vis[x2][y2]= vis[x.first][x.second]+1;
                        q.push({x2,y2});
                    }
                    
                    if(x2==0 || y2==0 || x2==n-1 || y2==m-1){
                        if(maze[x2][y2]=='.' && vis[x2][y2]!=1){
                            ans = min(ans,vis[x2][y2]-1); 
                        }
                    }
                }
                
                
                
                
                
            }
        }
        
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        bfs(maze,entrance);
        if(ans==INT_MAX)return -1;
        else return ans;
    }
};