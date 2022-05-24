class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char>a;
        stack<int>b;
        b.push(-1);
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                a.push(s[i]);
                b.push(i);
            }
            else if(!a.empty()&&s[i]==')'){
                a.pop();
                b.pop();
                ans=max(ans,i-b.top());
            }
            else{
                b.push(i);
            }
        }
        return ans;
    }
};