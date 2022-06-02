class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
         int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>mat;
        for(int i=0;i<m;i++){
            vector<int>v1;
            for(int j=0;j<n;j++){
                v1.push_back(matrix[j][i]);
            }
            mat.push_back(v1);
        }
        
        return mat;
    }
};