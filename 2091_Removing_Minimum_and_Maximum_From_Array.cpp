class Solution {
public:
    int minimumDeletions(vector<int>& nums) {//TC=O(n), SC=O(1)
        int n=nums.size();
        int minidx=min_element(nums.begin(),nums.end())-nums.begin();
        int maxidx=max_element(nums.begin(),nums.end())-nums.begin();
        int lowidx=min(minidx,maxidx);
        int highidx=max(minidx,maxidx);
        return min({highidx+1,n-lowidx,lowidx+1+n-highidx});
    }
};
