class Solution {
public:
	static bool comp(const vector<int> &a, const vector<int> &b) {
		if(a[0] < b[0])
			return true;
		else if(a[0] > b[0])
			return false;
		else if(a[1] > b[1])
			return true;
		else
			return false;
	  } 
	  int maxEnvelopes(vector<vector<int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), comp);
		vector<int> dp;
		for (auto it : envelopes)
		{
			auto iter = lower_bound(dp.begin(), dp.end(), it[1]);
			if (iter == dp.end())
				dp.push_back(it[1]);
			else if (it[1] < *iter)
				*iter = it[1];
		}
		return dp.size();
	}
};