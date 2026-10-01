class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        //longest subarray jinme atleast 1 to ho hi
        //fir usko ghatate jayenge
        //adjacent elements ka difference lenge if adj elements badh rhe honge toh, kyunki wo hi humari range se baahar honge
        //agar first element
        int sum=target[0];
        for(int i=1;i<n;i++){
            if(target[i]> target[i-1]){
                sum += target[i]- target[i-1];
            }
        }
        return sum;
    }
};