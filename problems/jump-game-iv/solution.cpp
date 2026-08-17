class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
        vector<bool> vis(n,false);
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        int steps=0;
        queue<int> q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int top = q.front();
                q.pop();
                if(top == n-1) return steps;
                if(top-1>=0 && !vis[top-1]){
                    vis[top - 1] = true;
                    q.push(top-1);
                } 
                if(top+1<n && !vis[top+1]){
                    vis[top+1]=true;
                    q.push(top+1);
                    
                } 
                 for(int j : mp[arr[top]]) {
                if(!vis[j]) {
                    vis[j] = true;
                    q.push(j);
                }
            }

            // VERY IMPORTANT
            mp[arr[top]].clear();
            }
            steps++;
        }
        return -1;
    }
};