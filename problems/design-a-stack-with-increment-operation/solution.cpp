class CustomStack {
public:
vector<int> stack;
int i;
    CustomStack(int maxSize) {
        stack.resize(maxSize);
        i=0;
    }
    
    void push(int x) {
        if(i<stack.size()){
            stack[i]=x;
            i++;
        }
        
    }
    
    int pop() {
        if(i==0) return -1;
        int k = i-1;
        i--;
        return stack[k];
    }
    
    void increment(int k, int val) {
        int j=0;
        while(j<stack.size() && j<k){
            stack[j]+=val;
            j++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */