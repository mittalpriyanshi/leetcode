class Solution {
public:
using ll = long long;
    long long wonderfulSubstrings(string word) {
        int cum_mask=0;
        int n= word.size();
        ll result=0;
        unordered_map<ll,ll> mp; //bitmasks and how many times seen
        mp[0]=1;
        for(int i=0;i<n;i++){
            int shift = word[i] -'a';
            int newMask = 1 << shift;
            cum_mask = cum_mask ^ newMask; //xor to update even/odd findingd
            //a^a =0  .... a^a^a !=0

            result += mp[cum_mask]; //i...j ke masks equal hain agar toh beech m even hain saare chars ki (including j) so 0 numbers with odd freq ( atmax 1 bola h kyunki)
           
            // now in i..j we see ki usme konse letter ki occurence odd hai
           // har ek letter k saath xor lenge to see if it exists in odd number
           //so 1 odd occurenece
            for(char c='a'; c<='j';c++){
                int shiftC= c-'a';
                ll check_xor = cum_mask ^ (1<< shiftC);
                result += mp[check_xor];

            }
            mp[cum_mask]++;
        }
        return result;
    }
};