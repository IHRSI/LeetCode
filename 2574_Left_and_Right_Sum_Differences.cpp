class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {//TC=O(n), SC=O(1)
        int n=nums.size();
        vector<int> ans(n);
        int rsum=accumulate(nums.begin(),nums.end(),0);
        int lsum=0;
        for(int i=0;i<n;++i){
            rsum-=nums[i];
            ans[i]=abs(rsum-lsum);
            lsum+=nums[i];
        }
        return ans;
    }
};
