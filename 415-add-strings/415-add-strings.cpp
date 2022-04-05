class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int>v;
        int c=0;
        string s1="";
        while(num1.length() || num2.length()){
            int x=0,y=0;
            if(num1.length()){
                x = num1.back()-'0';
                num1.pop_back();
            }
            
            if(num2.length()){
                y = num2.back()-'0';
                num2.pop_back();
            }
            
            int sum=c+ x+y;
            v.push_back(sum%10);
            c = sum/10;
            
        }
        if(c)v.push_back(c);
        
        reverse(v.begin(),v.end());
        
        for(auto i:v){
            s1+=(i+'0');
        }
        
        return s1;
    }
};