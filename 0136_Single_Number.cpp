class Solution {// TC- O(n) SC- O(n) - Not much effcient this Q needed bit manipulation
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int &ele : nums){
            m[ele]+=1;
        }
        for(auto &pr : m){
            if(pr.second==1) return pr.first;
        }
        return 0;
    }
};
// Better soln - x^x=0 and x^0=x using this concept
class Solution {//TC=O(n) SC=O(1)
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int val : nums){
            ans = ans ^ val;
        }
        return ans;
    }
};
