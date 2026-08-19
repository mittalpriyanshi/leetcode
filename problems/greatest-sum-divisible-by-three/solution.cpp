class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> r1, r2;
        int total = 0;
        for(int x : nums) {
            total += x;
            if(x % 3 == 1 && r1.size() < 2)
                r1.push_back(x);

            if(x % 3 == 2 && r2.size() < 2)
                r2.push_back(x);
        }

        int rem = total % 3;
        if(rem == 0) return total;
        int remove = INT_MAX;
        if(rem == 1) {
            // Remove one remainder-1 number
            if(r1.size() >= 1)
                remove = min(remove, r1[0]);
            // Remove two remainder-2 numbers
            if(r2.size() == 2)
                remove = min(remove, r2[0] + r2[1]);
        }
        else { // rem == 2
            // Remove one remainder-2 number
            if(r2.size() >= 1)
                remove = min(remove, r2[0]);
            // Remove two remainder-1 numbers
            if(r1.size() == 2)
                remove = min(remove, r1[0] + r1[1]);
        }
        return total - remove;
    }
};