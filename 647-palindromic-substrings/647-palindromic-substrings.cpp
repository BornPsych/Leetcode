class Solution {
public:
    int countSubstrings(string str) {
        
        int n = str.size();
        int res = 0;
        
        for(int i = 0; i < n; i++)
        {
            int left = i;
            int right = i;
            while(left >= 0 && right < n && str[left] == str[right])
            {
                res++;
                left--;
                right++;
            }
            
            left = i;
            right = i + 1;
            while(left >= 0 && right < n && str[left] == str[right])
            {
                res++;
                
                left--;
                
                right++;
            }
        }
        return res;
    }
};