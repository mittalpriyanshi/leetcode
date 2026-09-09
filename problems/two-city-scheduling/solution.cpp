class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //cost b - cost a
        //jinko A mai jaana sasta pdega unko A mai
        //jinko B mai sasta unko udhr
        //but differences dekhenge ki kisko jyaada sasta/mehnga pd rha
        sort(costs.begin(), costs.end(), [](vector<int>&a, vector<int>&b){
            return (a[1]-a[0])< (b[1]-b[0]);
        });
        int n= costs.size()/2;
        int ans =0;
        for(int i=0;i<n;i++){
            ans+=costs[i][1];
        }
        for(int i=n;i<2*n;i++){
            ans+=costs[i][0];
        }
        return ans;
    }
};