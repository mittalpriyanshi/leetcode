class Solution {
public:
vector<long long> dp;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<long long>> jobs(n,vector<long long>(3));
        for(int i=0;i<n;i++){
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end());
        vector<long long> starts(n);
        for(int i=0;i<n;i++){
            starts[i]=jobs[i][0];
        }
        dp.assign(n,0);
        return solve(0, starts, jobs);
    }
    int solve(int i, vector<long long>& starts,  vector<vector<long long>>& jobs){
        if(i>=starts.size()) return 0;
        if(dp[i]!=0) return dp[i];
        int nextStart = lower_bound(starts.begin(), starts.end(), jobs[i][1])-starts.begin();
        int take = jobs[i][2]+ solve(nextStart, starts, jobs);
        int skip = solve(i+1,starts,jobs);
        return dp[i] = max(take,skip);
    }
};