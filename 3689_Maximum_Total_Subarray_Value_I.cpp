class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {//TC=O(n), SC=O(1)
        int maxval=*max_element(nums.begin(),nums.end());
        int minval=*min_element(nums.begin(),nums.end());
        return k*1ll*(maxval-minval);
    }
};
