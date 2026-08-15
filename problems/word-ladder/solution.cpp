class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        set.erase(beginWord);
        while(!q.empty()){
            string w = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(w==endWord) return steps;
            for(int i=0;i<w.size();i++){
                char org = w[i];
                for(char c='a';c<='z';c++){
                    w[i]=c;
                    if(set.find(w)!=set.end()){
                        q.push({w,steps+1});
                        set.erase(w);
                    }
                }
                w[i]=org;
            }
        }
        return 0;
    }
};