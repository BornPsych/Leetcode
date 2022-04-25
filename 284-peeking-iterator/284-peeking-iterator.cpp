class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) { }

	int peek() { 
	    return Iterator(*this).next(); 
	}
};