class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int n = inventory.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(inventory[i]);
        }
        int count=0;
        int sum=0;
        while(!pq.empty() && count<orders){
            int t =pq.top();
            pq.pop();
            sum +=t;
            pq.push(t-1);
            count++;
        }
        return sum;
    }
};