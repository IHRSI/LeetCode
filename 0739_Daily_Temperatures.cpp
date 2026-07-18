//The stack stores indices of days whose next warmer day hasn't been found yet.
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {//TC=O(n), SC=O(n)
        int n=temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(0);
        for(int i=1;i<n;++i){
            while(!s.empty() && temperatures[s.top()]<temperatures[i]){
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
