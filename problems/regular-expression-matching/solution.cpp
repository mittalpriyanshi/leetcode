class Solution {
public:
map<pair<int,int>, bool> mp;
    bool isMatch(string s, string p) {
        int m = s.size(); //string
        int n = p.size(); //pattern
        return recurse(m,n,0,0,s,p);

    }
    bool recurse(int m, int n ,int i, int j,string s, string p ){
        if(i>=m && j>=n) return true;
        if(j>=n) return false; //pattern khatam, string remains
        if(mp.contains({i,j})) return mp[{i,j}];
        bool match = i<m && (s[i]==p[j] || p[j]=='.');
        if((j+1)<n && p[j+1]=='*'){
           mp[{i,j}] = (match && recurse(m,n,i+1,j,s,p)) || recurse(m,n,i,j+2,s,p);
           return mp[{i,j}];
        }
        if(match){
            mp[{i,j}] = recurse(m,n,i+1,j+1,s,p);
            return mp[{i,j}];
        }
        return false;
    }
};