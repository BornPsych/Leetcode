class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x=0;
        while(n){
            x+=(n)%2;
            //cout<<n<<endl;
            n/=2;
        }
        
        return x;
    }
};