class Solution {
public:
    typedef pair<int, int> pd;
    struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.first < b.first;
    }
};
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        priority_queue<pd, vector<pd>, myComp> p1;
        for(auto i:mp){
            p1.push({i.second,i.first});
        }
        
        vector<int>ans;
        while(k--){
            auto x = p1.top();
            ans.push_back(x.second);
            p1.pop();
        }
        
        return ans;
    }
};