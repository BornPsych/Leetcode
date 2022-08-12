class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>v;
        
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    v.push_back(j);
                    flag=1;
                }
            }
            if(flag){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
        
        for(int i=0;i<v.size();i++){
            for(int j=0;j<n;j++){
                matrix[j][v[i]]=0;
            }
        }
        
    }
};