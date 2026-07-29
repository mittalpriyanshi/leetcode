class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        // sort(rides.begin(), rides.end(), [](<vector<int>& ride1,<vector<int>& ride2 ){
        //     if(ride1[0]==ride2[0]){
        //          if (ride1[1]==ride2[1]) return ride1[2]>ride2[2];
        //          else return ride1[1] < ride2[1]; 
        //     }
        //     return ride1[0]<ride2[0];
        // });
        unordered_map<int, vector<pair<int,int>>> startAt(n+1);
        for(auto& r:rides){
            int start = r[0];
            int end = r[1];
            int prof = r[1]-r[0]+r[2];
            startAt[start].push_back({end,prof});
        }
        vector<long long> dp(n+1,0);
        //The maximum money you can have earned by the time you reach position i, i.e i as an end
        for(int i=1;i<=n;i++){
            dp[i]=max(dp[i], dp[i-1]);
            for(auto &[e,p]: startAt[i]){
                dp[e]= max(dp[e], dp[i]+p);
            }
        }
        return dp[n];
    }
};