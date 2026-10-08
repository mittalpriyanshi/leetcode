class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(stations.empty()){
            if(startFuel >= target) return 0;
            else return -1;
        }
        sort(stations.begin(), stations.end());
        int n = stations.size();
        //max stops you can take are n and least is 0
        vector<int> dp(n+1, -1);
        //dp[j] = max distance i can reach with j number of stops
        dp[0]= startFuel;
        for (int i=0;i<n;i++){
            //saare stations par traverse krenge 
            int pos = stations[i][0];
            int nextMaxDist = stations[i][1];

            //and ye dekhenge can i use this station as my jth refeuling station??
            //like supppose i have station no. 2 and i'll see can i use this as my 1st stop, or 2nd stop..
            for(int j=i+1;j>=1;j--){
                //can i even reach this station?
                //uske liye dp[j-1] check krna pdega ki kya isse phle 0 stops lekr hum idhr tk pohoch paa rhe the (to take it as our 1st stop)
                if(dp[j-1]>=pos){
                    dp[j] = max(dp[j], dp[j-1] + nextMaxDist);
                }
            }
        }
        for(int i=0;i<=n;i++){
            if(dp[i]>=target) return i;
        }
        return -1;
    }
};