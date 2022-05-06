class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int count=0;
        for(auto i:s){
            if(!st.empty() && st.top().first==i){
                count=st.top().second +1;
            }else count=1;
            
            st.push({i,count});
            
            if(count==k){
                while(count--){
                    st.pop();
                }
            }
        }
        
        string ans="";
        while(st.size()){
            ans+=st.top().first;
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};