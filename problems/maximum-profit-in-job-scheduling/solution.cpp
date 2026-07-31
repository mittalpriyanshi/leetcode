class Solution {
public:
vector<int> dp;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<long long>> jobs(n,vector<long long>(3));
        for(int i=0;i<n;i++){
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end());

        vector<long long> starts;
        for (auto &job : jobs)
            starts.push_back(job[0]);

        dp.assign(n, -1);
        return solve(0, jobs, starts);
    }
     int solve(int i, vector<vector<long long>> &jobs, vector<long long> &starts) {

        if (i >= jobs.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // Find first job whose start >= current end
        int next = lower_bound(starts.begin(), starts.end(), jobs[i][1]) - starts.begin();

        int take = jobs[i][2] + solve(next, jobs, starts);
        int skip = solve(i + 1, jobs, starts);

        return dp[i] = max(take, skip);
    }
};