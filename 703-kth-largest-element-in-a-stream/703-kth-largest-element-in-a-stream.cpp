class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        sz=k;
        sort(nums.begin(),nums.end(),greater<int>());
        int n = nums.size();
        for(int i=0;i<min(k,n);i++){
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        if(pq.size()<sz){
            pq.push(val);
            return pq.top();
        }
        int x = pq.top();
        if(val>=x){
            pq.pop();
            pq.push(val);
        }
        
        return pq.top();
        return 1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */