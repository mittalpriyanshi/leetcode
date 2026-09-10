class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
         vector<int> indegree(n,0);
        //  vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){     
            //adj[i].push_back(favorite[i]);
            indegree[favorite[i]]++;
        }
        //max of length of longest cycle > 2
        // vs length of acylic chains with mutual favourites, i.e
        // chain upto A + A<->B (mutuals) + cycle upto B -> and esa saare mutuals k saath we can do
        vector<int> chainLen(n);
        vector<bool> vis(n, false);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node]=true;
            int next = favorite[node];
            chainLen[next] = chainLen[node]+1; 
            // storing chain lens to calculate this part --> chain upto A + A<->B (mutuals) + cycle upto B
            indegree[next]--;
            if(indegree[next]==0) q.push(next);
        }
        int maxLenCycle = 0, maxLenChain=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int chainLength=0;
                int curr =i;
                while(!vis[curr]){
                    vis[curr] = true;
                    curr = favorite[curr];
                    chainLength++;
                }
                if(chainLength ==2){
                maxLenChain = max(maxLenChain, chainLen[i]+chainLen[favorite[i]]+2);
            }
            else{
                maxLenCycle  = max(maxLenCycle , chainLength);
            }
            }
        }
        return max(maxLenCycle, maxLenChain);
    }
};