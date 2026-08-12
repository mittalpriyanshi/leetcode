class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n=nums.size();
         unordered_map<int,int> freq;
        int last=-1;
        int count=0;
        int prefix=0;
        freq[0]=-1;
        for(int i=0;i<n;i++){
            prefix+= nums[i];
            if(freq.find(prefix-target) !=freq.end() && freq[prefix-target] >=last){
                count++;
                last=i;
            }
            freq[prefix]=i;
        }
       
        //-1 3 5 1 4 2...
        //-1 2 7 8 12 14..
        //we can find greedily, jese hi mil rha lelo usko
       
        return count;

    }
};