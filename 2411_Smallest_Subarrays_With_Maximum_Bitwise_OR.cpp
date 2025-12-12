class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {//TC=O(n*32)~O(n), SC=O(31)~O(1)
        int n=nums.size();
        vector<int> ans(n);
        vector<int> pos(31,-1);
        for(int i=n-1;i>=0;--i){
            int mxidx=i;
            for(int bit=0;bit<31;++bit){
                if(!(nums[i]& (1<<bit))){
                    mxidx=max(mxidx,pos[bit]);
                }
                else pos[bit]=i;
            }
            ans[i]=mxidx-i+1;
        }
        return ans;
    }
};
