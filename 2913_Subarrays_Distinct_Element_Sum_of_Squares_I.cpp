class Solution {
public:
    int sumCounts(vector<int>& nums) {//TC=O(n^2), SC=O(n)
        int ans=0,n=nums.size();
        for(int i=0;i<n;++i){
            unordered_set<int> us;
            for(int j=i;j<n;++j){
                us.insert(nums[j]);
                ans+=us.size()*us.size();
            }
        }
        return ans;
    }
};
