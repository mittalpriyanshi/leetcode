class Solution {
public:
long long MOD =1e9+7;
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        if(n==3 && nums[0]==nums[1] && nums[1]==nums[2]) return 1;
        vector<long> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        // 1 2 2 2 5 0
        // 1 3 5 7 12 12 
        // 1 | 2 |2 2 5 0
        // prefix[i]<= prefix[j]-prefix[i] <= prefix[n-1] - prefix[j]
        long long ans=0;
        long total = prefix[n-1];
        for(int i=0;i<n-2;i++){
            long left = 2* prefix[i];
            long right = (total+left)/2;
            int l=i+1;
            int r = n-2;
            int midstart;
            while(l<=r){
                midstart= (l+r)/2;
                if(prefix[ midstart]>= left) r= midstart-1;
                if(prefix[ midstart]< left) l= midstart+1;
            }
            int midend;
            l=midstart;
            r = n-2;
            while(l<=r){
                midend= (l+r)/2;
                if(prefix[ midend]> right) r= midend-1;
                if(prefix[ midend]<= right) l= midend+1;
            }
            ans = (ans + midend-midstart+1)% MOD;
        }
        return ans;
    }
};