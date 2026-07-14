class DSU {
public:
    vector<char> parent;
    vector<int> size;
    
    DSU() {
        parent.resize(26);
        size.resize(26, 1); 
        for(int i = 0; i < 26; i++){
            parent[i] = i + 'a'; 
        }
    }
    
    char findUlPar(char ch){
        if(parent[ch-'a'] == ch) return ch;
        return parent[ch-'a'] = findUlPar(parent[ch-'a']);
    }
    
    void doUnion(char a, char b){
        char parent1 = findUlPar(a);
        char parent2 = findUlPar(b);
        if(parent1 == parent2) return;
        
        if(size[parent1-'a'] < size[parent2-'a'] ){
            parent[parent1-'a'] = parent2 ;
            size[parent2-'a'] += size[parent1-'a'];
        }
        else{
            parent[parent2-'a'] = parent1;
            size[parent1-'a'] += size[parent2-'a'];
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU con;
        
        // PASS 1: Build the DSU using ONLY the "==" equations
        for(auto e : equations) {
            if(e[1] == '=') {
                con.doUnion(e[0], e[3]);
            }
        }
        
        // PASS 2: Check for contradictions using ONLY the "!=" equations
        for(auto e : equations) {
            if(e[1] == '!') {
                if(con.findUlPar(e[0]) == con.findUlPar(e[3])) {
                    return false;
                }
            }
        }
        
        return true;
    }
};