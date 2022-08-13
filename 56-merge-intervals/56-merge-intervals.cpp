class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>>v;
        sort(in.begin(),in.end());
        for(int i=0;i<in.size();i++){
            int x=0,x1=in[i][0];
            while(true){
                x= max(x,in[i][1]);
                if(i==in.size()-1 || x<in[i+1][0]){
                    break;
                }
                i++;
            }
            
            v.push_back({x1,x});
        }
        return v;
    }
};