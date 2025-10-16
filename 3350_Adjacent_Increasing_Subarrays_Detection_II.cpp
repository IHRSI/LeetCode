class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {//TC=O(n), SC=O(1)
        int n=nums.size();
        int ct=1,prevct=0;
        int ans=0;
        for(int i=1;i<n;++i){
            if(nums[i]>nums[i-1]) ++ct;
            else{
                prevct=ct;
                ct=1;
            }
            ans=max(ans,min(ct,prevct));
            ans=max(ans,ct/2);
        }
        return ans;
    }
};
