class Solution {
public:
    int maxArea(vector<int>& height) {
        int st=0,en=height.size()-1;
        int maxx=0;
        
        while(st<=en){
            int minn = min(height[st],height[en]);
            int ans = minn*(en-st);
            maxx = max(ans,maxx);
            
            if(minn==height[st]){
                st++;
            }else if(minn==height[en]){
                en--;
            }
            
        }
        
        return maxx;
    }
};