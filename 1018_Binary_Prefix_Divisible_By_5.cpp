class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {//TC=O(n), SC=O(1)
        int n=nums.size();
        vector<bool> ans(n);
        int num=0;
        for(int i=0;i<n;++i){
            num=((num<<1)+nums[i])%5;
            if(num==0) ans[i]=1;
            else ans[i]=0;
        }
        return ans;
    }
};
