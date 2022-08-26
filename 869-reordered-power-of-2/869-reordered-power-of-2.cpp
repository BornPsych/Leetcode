class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        
        sort(s.begin(),s.end());
        
        long long m=1;
        for(int i=1;i<36;i++){
            string s1 = to_string(m);
            sort(s1.begin(),s1.end());
            if(s==s1)return true;
            m*=2;
        }
        
        return false;
    }
};