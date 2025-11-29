class Solution {
public:
    int minOperations(vector<int>& nums, int k) {//TC=O(n), SC=O(1)
        return accumulate(nums.begin(),nums.end(),0)%k;
    }
};
