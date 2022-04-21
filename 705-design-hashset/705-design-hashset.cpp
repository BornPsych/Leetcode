class MyHashSet {
public:
    int ar[1000005];
    MyHashSet() {
        for(int i=0;i<1000005;i++){
            ar[i]=0;
        }
    }
    
    void add(int key) {
        ar[key]=1;
    }
    
    void remove(int key) {
        ar[key]=0;
    }
    
    bool contains(int key) {
        return ar[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */