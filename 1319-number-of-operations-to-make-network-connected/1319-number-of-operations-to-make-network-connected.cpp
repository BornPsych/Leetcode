class Solution {
public:
    vector<int>parent;
    int count=0;
    int find(int x){
        if(parent[x]<0){
            return x;
        }
        
        return parent[x] = find(parent[x]);
    }
    
    void merge(int x,int y){
        x = find(x);
        y = find(y);
        
        if(x==y){
            count++;
            return;
        }
        parent[x] = y;
    }
    
    int makeConnected(int n, vector<vector<int>>& con) {
        for(int i=0;i<n;i++){
            parent.push_back(-1);
        }
        
        for(auto i:con){
            merge(i[0],i[1]);
        }
        int count1=0;
        for(int i=0;i<n;i++){
            if(parent[i]<0)count1++;
        }
        count1--;
        
        if(count1>count)return -1;
        else return min(count,count1);
        
    }
};