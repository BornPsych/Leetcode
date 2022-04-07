class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
         sort(in.begin(),in.end());
        vector<vector<int>>v;
         for(int i=0;i<in.size();i++){
            int x1 = in[i][0],x2=0;
             while(true){
                 x2 = max(x2,in[i][1]);
                 if(i==in.size()-1 || x2<in[i+1][0]){x2=max(in[i][1],x2);break;}
                 i++;
             }
             
             v.push_back({x1,x2});
         }
        
        
        return v;
    }
};