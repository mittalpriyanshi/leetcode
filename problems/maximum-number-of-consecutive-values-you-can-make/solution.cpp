class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int ans=0;
        sort(coins.begin(), coins.end());
        int start=1;
        if(coins[0]!=1) return 1;
        ans = 2;
        int s = start+1;
        for(int i=1;i<coins.size();i++){
            int limit = start+ coins[i];
            while(true){
                if(s> limit) break;
                if(s>=coins[i] && s<=limit){
                    s++;
                    ans++;
                } 
                else if(s < limit && s < coins[i]) return ans;
            }
            start=s-1;
        }
        return ans;
        
    }
};