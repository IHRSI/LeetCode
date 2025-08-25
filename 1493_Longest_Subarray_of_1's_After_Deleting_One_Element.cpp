class Solution {
public:
    int longestSubarray(vector<int>& nums) {//TC=O(2n)=O(n) , SC=O(1)
        int ans=0;
        int ct0=0;
        int srt=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]==0) ++ct0;
            while(ct0>1){
                if(nums[srt]==0) --ct0;
                ++srt;
            }
            ans=max(ans,i-srt);
        }
        return ans;
    }
};
