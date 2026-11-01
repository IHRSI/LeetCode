class Solution {
public:
    int minMoves(vector<int>& nums) {//TC=O(n), SC=O(1)
        return accumulate(nums.begin(),nums.end(),0)-nums.size()*(*min_element(nums.begin(),nums.end()));
    }
};
