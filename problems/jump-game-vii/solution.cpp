class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s[n-1]=='1') return false;
        queue<int> q;
        vector<bool> vis(n,false);
        vis[0]=true;
        q.push(0);
        while(!q.empty()){
            int t= q.front();
            q.pop();
            if(t==n-1) return true;
            int start = t+ minJump;
            int end = t+maxJump;
            for(int i=start;i<=end;i++){
                if(!vis[i] && s[i]=='0'){
                    vis[i]=true;
                    q.push(i);
                } 
            }
        }
        return false;
    }
};