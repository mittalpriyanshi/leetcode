class MedianFinder {
public:
 priority_queue<int, vector<int>>pqmin;
 priority_queue<int, vector<int>, greater<int>>pqmax;
    MedianFinder() {
        while(!pqmin.empty()) pqmin.pop();
        while(!pqmax.empty()) pqmax.pop();
    }
    
    void addNum(int num) {
        pqmin.push(num);
        pqmax.push(pqmin.top());
        pqmin.pop();
        //min waale mai ek element jyaada rkho if right m jyaada hai(odd k case mai)
        if (pqmax.size() > pqmin.size()) {
            pqmin.push(pqmax.top());
            pqmax.pop();
        }
    }
    
    double findMedian() {
       if(pqmin.size() > pqmax.size()) return pqmin.top();
       return double( pqmin.top() + pqmax.top()) /2.00;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */