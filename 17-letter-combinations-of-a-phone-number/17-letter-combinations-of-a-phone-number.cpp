class Solution {
public:
    vector<string>s1;
    vector<string>v1 = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string s,string op){
        if(s.length()==0){
            if(op.length()>0)s1.push_back(op);
            return;
        }
        int x = s[0]-'0';
        s.erase(s.begin());
        for(int i=0;i<v1[x-2].size();i++){
            string op1 = op + v1[x-2][i];
            solve(s,op1);
        }
    }
    
    vector<string> letterCombinations(string s) {
        solve(s,"");
        return s1;
    }
};