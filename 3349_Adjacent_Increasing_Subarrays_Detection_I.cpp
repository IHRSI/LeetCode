class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {//TC=O(n), SC=O(1)
        int n=nums.size();
        int ct=1;
        int prevct=0;
        for(int i=1;i<n;++i){
            if(nums[i]>nums[i-1]){
                ++ct;
            }
            else{
                prevct=ct;
                ct=1;
            }
            if(ct>=2*k) return true;
            if(min(ct,prevct)>=k) return true;
        }
        return false;
    }
};
