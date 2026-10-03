class LRUCache {
public:
list<int> dll; //key
unordered_map<int, pair<list<int>::iterator, int>> mp; //key, adress, value
int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        makeRecentlyUsed(key);
        return mp[key].second;
    }
    void makeRecentlyUsed(int key){
        auto oldadress = mp[key].first;
        dll.erase(oldadress);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }
    void put(int key, int value) {
        if(mp.find(key)!= mp.end()){
            mp[key].second = value;
            makeRecentlyUsed(key);
        }
        else{
            dll.push_front(key);
            mp[key].first = dll.begin();
            mp[key].second = value;
            n--;
        }
        if(n<0){
            int keytobedeleted= dll.back();
            dll.pop_back();
            mp.erase(keytobedeleted);
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */