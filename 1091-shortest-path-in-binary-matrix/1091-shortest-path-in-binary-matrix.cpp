class Solution {
public:
    int bfs(vector<vector<int>>& grid){
        vector<vector<int>>visited(grid.size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                visited[i].push_back(0);
            }
        }
        if(grid[0][0]==1)return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>x1 = {0,1,0,-1,1,1,-1,-1};
        vector<int>y1 = {1,0,-1,0,1,-1,1,-1};
        int ans=0;
        visited[0][0]=1;
        while(q.size()){
            auto x = q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int x2 = x.first +  x1[i];
                int y2 = x.second + y1[i];
                if(x2>=0 && y2>=0 && x2<grid.size() && y2<grid.size()){
                    if(!visited[x2][y2] && grid[x2][y2]==0){
                        q.push({x2,y2});
                        visited[x2][y2]=visited[x.first][x.second]+1;
                    }
                }
            }
        }
        
        if(visited[grid.size()-1][grid.size()-1]==0)return -1;
        else return visited[grid.size()-1][grid.size()-1];
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};