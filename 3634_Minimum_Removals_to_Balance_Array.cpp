class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {//TC=O(nlogn+n)~O(nlogn), SC=O(logn)
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=n;
        int l=0,r=0;
        while(r<n && l<=r){
            if(nums[r]+0ll<=nums[l]*1ll*k){
                ++r;
            }
            else ++l;
            ans=min(ans,n-(r-l));
        }
        return ans;
    }
};
