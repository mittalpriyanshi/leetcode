class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> prefix(n);
        prefix[0]= nums[0];
        for(int i=1;i<n;i++){
            prefix[i]= prefix[i-1]+nums[i];
        }
        unordered_map<int,int> freq;
        unordered_map<int,int> index;
        for(int i=0;i<n;i++) index[prefix[i]]=i;
        //-1 3 5 1 4 2...
        //-1 2 7 8 12 14..
        //we can find greedily, jese hi mil rha lelo usko
        int last=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(freq[prefix[i]-target] && index[prefix[i]-target]>= last ){
                count++;
                last =i;
            }
            freq[prefix[i]]++;
        }
        return count;

    }
};