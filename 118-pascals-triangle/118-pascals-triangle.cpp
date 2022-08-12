class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        
        if(n==1){
            vector<int>v;
            v.push_back(1);
            ans.push_back(v);
        }else if(n==2){
            vector<int>v;
            v.push_back(1);
            ans.push_back(v);
            v.push_back(1);
            ans.push_back(v);
        }else{
            vector<int>v;
            v.push_back(1);
            ans.push_back(v);
            v.push_back(1);
            ans.push_back(v);
            
            for(int i=2;i<n;i++){
                v.clear();
                v.push_back(1);
                for(int j=0;j<ans[i-1].size()-1;j++){
                    v.push_back(ans[i-1][j] + ans[i-1][j+1]);
                }
                v.push_back(1);
                ans.push_back(v);
                
            }
        }
        
        return ans;
    }
};