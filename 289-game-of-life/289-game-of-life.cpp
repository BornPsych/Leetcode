class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        int x1[8] = {0,1,0,-1,1,1,-1,-1};
        int y1[8] = {1,0,-1,0,-1,1,1,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count1=0;
                int count0=0;
                for(int k=0;k<8;k++){
                    int x2 = i+ x1[k];
                    int y2 = j+ y1[k];
                    if(x2>=0 && y2>=0 && x2<n && y2<m){
                        if(board[x2][y2]==1 || board[x2][y2]==2)count1++;
                        else count0++;
                    }
                }
                if((count1==2 || count1==3) && board[i][j]==1)board[i][j]=1;
                else if(count1<2 && board[i][j]==1)board[i][j]=2;
                else if(count1>3 && board[i][j]==1)board[i][j]=2;
                else if(count1==3 && board[i][j]==0)board[i][j]=3;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==2)board[i][j]=0;
                if(board[i][j]==3)board[i][j]=1;
            }
        }
    }
};