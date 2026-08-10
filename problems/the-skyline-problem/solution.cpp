class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> events;
        for(auto v: buildings){
            int start = v[0];
            int end= v[1];
            int h = v[2];
            events.push_back({start,h});
            events.push_back({end,-h});
        }
        sort(events.begin(), events.end(), [](auto& a, auto& b){
            return a.first<b.first;
        });
        multiset<int> activeH;
        activeH.insert(0);
        int prevMax=0;
        int currMax;
        vector<vector<int>> ans;
        for(int i=0;i<events.size();){
            int x = events[i].first;
            while(i<events.size() && events[i].first==x ){
                if(events[i].second>0){
                    activeH.insert(events[i].second);
                }
                 if(events[i].second<0){
                    activeH.erase(activeH.find(-events[i].second));
                }
                i++;
            }
            currMax = *activeH.rbegin();
            if(currMax!=prevMax) {
                ans.push_back({x,currMax});
            prevMax = currMax;
            }
        }
        return ans;
    }
};