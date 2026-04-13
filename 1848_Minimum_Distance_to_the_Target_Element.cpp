class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {//TC=O(n), SC=O(1)
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;++i){
            if(nums[i]==target) ans=min(ans,abs(i-start));
        }
        return ans;
    }
};
