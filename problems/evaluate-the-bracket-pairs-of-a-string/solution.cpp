class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto k: knowledge){
            mp[k[0]] = k[1];
        }
        int i=0,j=0;
        string res="";
        while(i<=j && j<s.size()){
            while(i<=j && j<s.size() && s[i]!='(' && s[i]!=')') {
                res+=s[i];
                i++; j++;
            }
            if(s[i]=='('){
                while(s[j]!=')') j++;
                string key = s.substr(i+1, j-i-1);
                if(mp.find(key)!=mp.end()){
                    res+= mp[key];
                }
                else res+='?';
                j++;
                i=j;
            }
        }
        return res;
    }
};