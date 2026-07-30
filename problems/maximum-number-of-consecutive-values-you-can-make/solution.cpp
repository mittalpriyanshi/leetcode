class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
    sort(coins.begin(), coins.end());
      long long reach =0;
      for(int coin : coins){
        if(coin > reach+1) break;
         reach+=coin;
      }
      return reach+1;
        
    }
};