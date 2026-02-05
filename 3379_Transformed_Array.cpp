class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {//TC=O(n), SC=O(n)
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;++i){
            ans[i]=nums[(i+nums[i]%n+n)%n];
            //res[i]=nums[((i + nums[i]) % n + n) % n];
        }
        return ans;
    }
};
