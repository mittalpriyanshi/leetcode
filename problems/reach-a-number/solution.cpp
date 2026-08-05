class Solution {
public:
    int reachNumber(int target) {
       
        // solution approach- https://leetcode.com/problems/reach-a-number/solutions/1707155/c-easy-and-simple-solution-beats-100-in-sdi0r/
        target = abs(target);
        long n =1;
        while(!(target<= n*(n+1)/2 && (target & 1) == ((n*(n+1)/2)&1))) n++; //either both even or oth odd
        return n;

    }
};