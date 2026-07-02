class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {//TC=O(n^2), SC=O(1)
        int n=nums.size();
        int subarrct=0;
        for(int i=0;i<n;++i){
            int ct=0;
            for(int j=i;j<n;++j){
                if(nums[j]==target) ++ct;
                else --ct;
                if(ct>0) ++subarrct;
            }
        }
        return subarrct;
    }
};
