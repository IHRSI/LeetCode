//Increasing Monotonic Stack
class Solution {
public:
    int minOperations(vector<int>& nums) {//TC=O(n), SC=O(n)
        int op=0;
        stack<int> s;
        for(int e: nums){
            while(!s.empty() && e<s.top()){
                s.pop();
            }
            if(e==0) continue;
            while(s.empty() || s.top()<e){
                s.push(e);
                ++op;
            }
        }
        return op;
    }
};

class Solution {//TLE
public:
    int minOperations(vector<int>& nums) {//TC=O(n^2), SC=O(n)
        unordered_set<int> us(nums.begin(),nums.end());
        int op=0;
        for(int tar: us){
            if(tar==0) continue;
            bool flow=0;
            for(int e: nums){
                if(e==tar){
                    if(!flow){
                        flow=1;
                        ++op;
                    }
                }
                else if(e<tar) flow=0;
            }
        }
        return op;
    }
};
