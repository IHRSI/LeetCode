class Solution {
public:
    int minPairSum(vector<int>& nums) {//TC=O(nlogn+n/2)~O(nlogn), SC=O(logn)
        sort(nums.begin(),nums.end());
        int max_sum=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n/2;++i){
            max_sum=max(max_sum,nums[i]+nums[n-i-1]);
        }
        return max_sum;
    }
};
