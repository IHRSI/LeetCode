class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {//TC=O((T+n)logn) ,SC=O(n)
        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;//Min heap
        int day=events[0][0];
        int i=0,attended=0;
        while(i<n || !pq.empty()){//Worst case we iterate day 1 in each each iteration assume events[n-1][1]=T(max day) TC=O(Tlogn*2)=O(Tlogn)
            if(pq.empty()) day=events[i][0];
            //Inside while maximum we push and pop once all elements of events i.e we visit them 2 times. They are O(logn) operations due to pq
            while(i<n && day==events[i][0]){
                pq.push(events[i][1]);//O(logn)
                ++i;
            }
            if(!pq.empty()){
                pq.pop();//O(logn) - greedy approach - deleting the event which has early end date
                ++attended;
            }
            ++day;
            while(!pq.empty() && pq.top()<day) pq.pop();
        }
        return attended;
    }
};
