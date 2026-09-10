class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 1;
        int count=1;
        vector<vector<bool>> dp(2, vector<bool>(n,false)); //which number, which jump
        dp[0][n-1]=true;  //0 jump to reach 
        dp[1][n-1] = true;
        map<int,int> mp; //number, index
        mp[arr[n-1]] = n-1;
        for(int i=n-2;i>=0;i--){
            //odd jump
            // lower_bound finds the exact match, or the first thing strictly larger
           auto oddTarget = mp.lower_bound(arr[i]);
            if(oddTarget!= mp.end()){
                int nextTarget = oddTarget->second; //index chaiye
                dp[1][i] = dp[0][nextTarget];
            }

            //even
            auto evenTarget = mp.upper_bound(arr[i]);
            if (evenTarget != mp.begin()) {
                --evenTarget; // Step back to get <= arr[i]
                int targetIndex = evenTarget->second;
                dp[0][i] = dp[1][targetIndex]; // If we take an Even jump, the next one is Odd
            }
            if (dp[1][i]) {
                count++;
            }
            mp[arr[i]] = i;
        }
        return count;
    }
};