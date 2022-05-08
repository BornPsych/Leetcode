class Solution {
public:
    int strStr(string ha, string ne) {
        int n = ha.length() - ne.length()+1;
        if(n<0)return -1;
        for(int i=0;i<n;i++){
            if(ha[i]==ne[0]){
                int j=ne.length();
                while(j--){
                    cout<<ne[j]<<" "<<ha[i+j]<<endl;
                    if(ne[j]!=ha[i+j])break;
                }
                cout<<j<<" ";
                if(j==-1)return i;
            }
        }
        
        return -1;
    }
};