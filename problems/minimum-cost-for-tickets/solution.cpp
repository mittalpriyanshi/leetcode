class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //dp[i] = min cost to travvel till that days[ith] day
        //dp[0] = "" till day1, dp[1]="" till day4...
        sort(days.begin(), days.end());
        int maxDay = days[days.size()-1];
        vector<bool> daysToTravel(maxDay,false);
        for(int i=0;i<days.size();i++){
            daysToTravel[days[i]]=true;
        }
        return solve(days,costs,maxDay,0,1, daysToTravel);
    }
    int solve(vector<int>& days, vector<int>& costs,int maxDay, int total,int d, vector<bool>& dtt){
        if(d>maxDay) return total;
        while(!dtt[d]) d++;
        int cost1 = costs[0] + solve(days,costs,maxDay,total,d+1,dtt);
        int cost7 = costs[1] + solve(days,costs,maxDay,total,d+7,dtt);
        int cost30 = costs[2] + solve(days,costs,maxDay,total,d+30,dtt);
        return total = min(min(cost1, cost7), cost30);
    }
};