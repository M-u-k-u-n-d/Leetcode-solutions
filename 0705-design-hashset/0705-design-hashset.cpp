class MyHashSet {
    map<int,int> mpp;
public:
    MyHashSet() {
        
    }
    void add(int key) {
        ++mpp[key];
    }
    void remove(int key) {
        mpp[key] = 0;
    }
    bool contains(int key) {
        if(mpp[key] > 0) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */