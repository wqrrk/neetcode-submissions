class MyHashSet {
private: 
    vector<int> data; 
public:
    MyHashSet() {}
    
    void add(int key) {
        if (find(data.begin(), data.end(), key) == data.end()) { 
            data.push_back(key);
        }
    }
    
    void remove(int key) {
        auto element = find(data.begin(), data.end(), key); 
        if (element != data.end()) { 
            data.erase(element); 
        }
    }
    
    bool contains(int key) {
        return find(data.begin(), data.end(), key) != data.end();
    }
};