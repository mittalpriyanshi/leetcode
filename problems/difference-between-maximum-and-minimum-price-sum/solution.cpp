class Solution {
public:
int m;
vector<vector<int>> adj;
vector<long long> down;
long long ans =0;

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        m =n;
        adj.assign(n, vector<int>());
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        down.resize(n);
        // phle kisi arbitary root se saare subtrees ka path sum nikal lo, including their nodes sum individually as well
        dfs1(price,0,-1);
        dfs2(price,0,-1,0);
        return ans;

    }
    long long dfs1(vector<int>& price, int node,int parent){
        down[node] = price[node];
        for(int child : adj[node]){
            if(child == parent) continue;
            dfs1(price, child, node);
            down[node] = max(down[node], (long long)price[node]+ down[child]);
        }
        return down[node];
    }
    //now re rooting

   void dfs2(vector<int>& price, int node,int parent, long long parentSum){
        long long best1=0;
        long long best2 =0;
        int bestChild =-1;
        // to find top two child contributions
        for(int child: adj[node]){
            if(child==parent) continue;
            if(down[child] > best1){
                best2 = best1;
                best1 = down[child];
                bestChild = child;
            }
            else if(down[child]> best2){
                best2 = down[child];
            }
        }
        //if currnode is leaf
        if(adj[node].size()==1)
        ans = max(ans, max(parentSum, best1));

        //re-root
        for(int child: adj[node]){
            if(child==parent) continue;
             long long bestOtherSide;
            if(child==bestChild){

               // Can't use v's own subtree.
                bestOtherSide =
                    max(parentSum, best2);

            } else {

                // We can use the best child.
                bestOtherSide =
                    max(parentSum, best1); 
            }

            long long nextParentSum =
                price[node] + bestOtherSide;


            dfs2(price,child, node, nextParentSum);
        }
    }
};