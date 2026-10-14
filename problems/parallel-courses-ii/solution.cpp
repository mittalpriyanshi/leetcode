class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<vector<int>> adj(n);
        vector<int> outdegree(n,0);
        int sems=0;
        for(auto r: relations){
            r[0]--;
            r[1]--;
            adj[r[0]].push_back(r[1]);
            outdegree[r[1]]++;
        }
        //jiski outdegree 0 wo lenge
        queue<int> q;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int size = q.size();
            if(size%k==0) sems+= size/k;
            else sems+= size/k +1;
            for(int i=0;i<size;i++){
                int idx = q.front();
                q.pop();
                for(int next: adj[idx]){
                    outdegree[next]--;
                    if(outdegree[next]==0) q.push(next);
                }
            }
           
        }
        return sems;
    }
};