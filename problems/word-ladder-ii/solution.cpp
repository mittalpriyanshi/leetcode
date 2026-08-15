class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        if(!set.count(endWord)) return {};
       
        vector<vector<string>> ans;
        unordered_map<string,int> depth;
        depth[beginWord]=1;
        queue<string> q;
        q.push(beginWord);
        set.erase(beginWord);
        while(!q.empty()){
            string w = q.front();
            q.pop();
            int d=depth[w];
            if(w==endWord) break;
            for(int i=0;i<w.size();i++){
                char org = w[i];
                for(char c='a'; c<='z';c++){
                    w[i]=c;
                    if(set.count(w) && !depth.count(w)){
                        depth[w]=d+1;
                        q.push(w);
                        set.erase(w);
                    }
                }
                w[i]=org;
            }
        }
        vector<string> seq = {endWord};
        dfs(endWord, beginWord, seq, depth, ans);
        return ans;
    }
    void dfs(string word, string begin, vector<string>& seq, unordered_map<string,int>& depth, vector<vector<string>>& ans){
        if(word==begin){
           reverse(seq.begin(), seq.end());
           ans.push_back(seq);
           reverse(seq.begin(), seq.end());
           return;
        }
        int steps= depth[word];
        for(int i=0;i<word.size();i++){
            char org = word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(depth.count(word) && depth[word]+1==steps){
                    seq.push_back(word);
                    dfs(word,begin,seq,depth,ans);
                    seq.pop_back();
                }
            }
            word[i]=org;
        }

    }
};