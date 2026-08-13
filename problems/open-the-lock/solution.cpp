class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> q;
        q.push({"0000", 0});
        unordered_set<string> vis(deadends.begin(), deadends.end());
        if(vis.count("0000")) return -1;
        vis.insert("0000");
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            string curr = f.first;
            int steps = f.second;
            if(curr==target) return steps;
            for(int i=0;i<4;i++){
                string copy = curr;
                copy[i] = (copy[i]-'0'+1)%10 +'0';
                if(!vis.count(copy)){
                    vis.insert(copy);
                    q.push({copy, steps+1});
                }
                copy = curr;
                copy[i] = (copy[i]-'0'+9)%10 +'0';
                if(!vis.count(copy)){
                    vis.insert(copy);
                    q.push({copy, steps+1});
                }
            }
        }
        return -1;
    }
};