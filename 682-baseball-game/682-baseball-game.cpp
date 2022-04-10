class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>ans;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"){
                ans.pop_back();
            }else if(ops[i]=="D"){
                int x = ans.back()*2;
                ans.push_back(x);
            }else if(ops[i]=="+"){
                int x = ans.back();
                ans.pop_back();
                int y = ans.back() + x;
                ans.push_back(x);
                ans.push_back(y);
            }else{
                int x = stoi(ops[i]);
                ans.push_back(x);
            }
        }
        int total=0;
        for(int i=0;i<ans.size();i++){
            total+=ans[i];
        }
        
        return total;
    }
};