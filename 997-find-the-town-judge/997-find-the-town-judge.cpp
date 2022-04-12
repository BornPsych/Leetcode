class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>a(n+1,0);
        for(auto i: trust){
            a[i[1]]++;
        }
        int x = 0;
        for(int i=0;i<n+1;i++){
            if(a[i]==n-1)x=i;
        }
        if(x==0)return -1;
        for(auto i: trust){
            if(i[0]==x)return -1;
        }
        return x;
    }
};