class Solution {
public:
    bool sumGame(string num) {
        int n= num.size();
        int sumLeft=0;
        int sumRight=0;
        int l=0, r=n-1;
        int countright=0, countleft=0;
        while(l<n/2 && r>=n/2){
            if(num[l]!='?') sumLeft += num[l]-'0';
            if(num[r]!='?') sumRight += num[r]-'0';
            if(num[l]=='?') countleft++;
            if(num[r]=='?') countright++;
            l++; r--;
        }
        if(sumLeft==sumRight && countright+countleft==0) return false;
        if((countright+countleft)%2!=0) return true; //alice wins if odd ?
       
        return 2 * (sumLeft - sumRight) != 9 * (countright - countleft);
        
    }
};