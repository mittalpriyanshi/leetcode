class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int> freq; //frequency of letters
        for( char c: letters){
            freq[c]++;
        }
        //state- solve(i, freq map)
       
        return solve(0,freq,words,score);
       

    }
    int solve(int i, unordered_map<char,int> freq, vector<string>& words, vector<int>& score ){
        //if ith word ko take--> jab saare letters avl ho
        if(i==words.size()) return 0;
        bool all = true;
        int notTake = solve(i+1, freq, words, score);
        for(auto c: words[i]) {
            if(!freq.count(c) || freq[c]==0){
                all=false;
                break;
            }
            freq[c]--;
        }
        int scoreTake=0;
        if (!all) {
            return notTake;
        }
        else{
            //tak
            for(auto c: words[i]) {
            scoreTake += score[c-'a'];
            }
            return max(notTake,scoreTake+ solve(i+1, freq, words, score));
        }
        }
    
};