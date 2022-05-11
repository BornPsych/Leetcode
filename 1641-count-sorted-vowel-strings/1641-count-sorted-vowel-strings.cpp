class Solution {
public:
    int countVowelStrings(int n) {
        vector<int>v(5,1);
        n--;
        while(n--){
            for(int i=0;i<5;i++){
                int x=0;
                for(int j=i;j<5;j++){
                    x+=v[j];
                }
                v[i]=x;
            }
        }
        int ans=0;
        for(int i=0;i<5;i++){
            ans+=v[i];
        }
        return ans;
    }
};