class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) 
            return tasks.size();
        vector<int> freq(26,0);
        for(char c: tasks) 
            freq[c-'A']++;
        sort(freq.begin(),freq.end());
        int max_val = freq[25]-1; 
        int idle_slots = max_val*n; 
 
        for(int i=24;i>=0;i--) {
            idle_slots -= min(freq[i],max_val);    

            
        }
        return (idle_slots>0)?tasks.size()+idle_slots : tasks.size();
    }
};