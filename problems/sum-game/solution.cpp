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
        //Bob's optimal strategy is pairing: if Alice replaces a ? with a number x, Bob will replace a ? on the same side with 9 - x. 
        //This means every pair of ? allows Bob to add exactly 9 to that side's sum.
        //Because of this, Bob can only win if the initial difference between the left sum and right sum can be perfectly balanced by the difference in ?s.
    }
};