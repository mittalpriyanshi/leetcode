class StockPrice {
public:
    map<int, int> mp;
    multiset<int> s;
    StockPrice() {}

    void update(int timestamp, int price) {
        bool containsThisPrice = false;
        if (mp.find(timestamp) != mp.end()) {
            int org = mp[timestamp];
            for (auto [k, v] : mp) {
                if (v == price && k != timestamp) {
                    containsThisPrice = true;
                }
            }
            if (!containsThisPrice)
                s.erase(org);
            mp[timestamp] = price;
            s.insert(price);
        } else {
            mp[timestamp] = price;
            s.insert(price);
        }
    }

    int current() { return mp[prev(mp.end())->first]; }

    int maximum() { return *prev(s.end()); }

    int minimum() { return *s.begin(); }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */