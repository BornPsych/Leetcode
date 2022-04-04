class Solution {
public:
    void bfs(vector<vector<int>>& grid){
        int n= grid.size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        
        int v1[4]={0,1,0,-1};
        int v2[4]={1,0,-1,0};
        
        while(q.size()){
            auto p = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx = p.first + v1[i];
                int ny = p.second+ v2[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n && !grid[nx][ny]){
                    grid[nx][ny] = grid[p.first][p.second]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        bfs(grid);
        int mx = -1;
        for(auto i:grid){
            for(auto j:i){
                mx = max(mx,j-1);
            }
        }
        
        if(mx==0){return -1;}
        else return mx;
    }
};