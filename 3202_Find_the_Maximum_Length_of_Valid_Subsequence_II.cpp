// DP LIS variant
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {//TC=O(n^2), SC=O(k*n)
        int n=nums.size();
        int longest=0;
        vector<vector<int>> dp(k,vector<int>(n,1));
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                int mod=(nums[i]+nums[j])%k;
                dp[mod][i]=max(dp[mod][i],dp[mod][j]+1);
                longest=max(longest,dp[mod][i]);
            }
        }
        return longest;
    }
};
