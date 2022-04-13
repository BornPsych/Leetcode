class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>a;
        for(int i=0;i<n;i++){
            a.push_back({});
            for(int j=0;j<n;j++){a[i].push_back(0);}
        }
        
        int rowst=0,colst=0,rowen=n-1,colen=n-1,j=1;
        
        while(rowst<=rowen || colst<=colen){
            for(int i=colst;i<=colen;i++){
                a[rowst][i]=j;
                j++;
            }
            rowst++;
            for(int i=rowst;i<=rowen;i++){
                a[i][colen] = j;
                j++;
            }
            colen--;
            for(int i=colen;i>=colst;i--){
                a[rowen][i]=j;
                j++;
            }
            rowen--;
            for(int i=rowen;i>=rowst;i--){
                a[i][colst]=j;
                j++;
            }
            colst++;
        }
        
        return a;
    }
};