class MyHashMap {
    map<int,int> mpp;
   vector<bool> vis = vector<bool>(1000004,false);
public:
    MyHashMap() {
 
    }
    
    void put(int key, int value) {
        mpp[key] = value;
        vis[key] = 1;
    }
    
    int get(int key) {
        if(vis[key]) return mpp[key];
        return -1;
    }
    
    void remove(int key) {
        vis[key] = 0;
        mpp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */