class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        sort(courses.begin(), courses.end(),[](vector<int>& a, vector<int>& b){
           if(a[1]==b[1]) return a[0] <b[0];
            return a[1] < b[1];
        });
        int curr=0;
        priority_queue<int> maxHeap;
        for(auto c: courses){
            int dur = c[0];
            int ded = c[1];
            if(curr+dur<= ded){
                curr +=dur;
                maxHeap.push(dur);
            }
            else{
                if(!maxHeap.empty() && maxHeap.top() > dur){
                    curr = curr - maxHeap.top()+dur;
                    maxHeap.pop();
                    maxHeap.push(dur);
                }
            }
        }
        return maxHeap.size();
    }
};