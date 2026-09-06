//Same code as of II Q
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {//TC=O(n), SC=O(n)
        int n=nums.size();
        vector<int> minsuff(n);
        minsuff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;--i){
            minsuff[i]=min(minsuff[i+1],nums[i]);
        }
        int maxpre=INT_MIN;
        for(int i=0;i<n;++i){
            maxpre=max(maxpre,nums[i]);
            if((maxpre-minsuff[i])<=k) return i;
        }
        return -1;
    }
};
