class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n=position.size();
        int low = 1;
        int high = position[n-1]-position[0];
        int ans=0;
        while(low<=high){
            int mid = low + ((high-low)/2);
            if(canPlace(mid,position,m)){
                ans=mid;
                low =mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    bool canPlace(int dist, vector<int>& position, int balls){
        int lastPos = 0;
        int count=1;
        for(int i=1;i<position.size();i++){
            if(position[i]-position[lastPos]>=dist){
                count++;
                lastPos=i;
                if (count >= balls) return true;
            }
        }
        return false;
    }
};