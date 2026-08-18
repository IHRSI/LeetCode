class Solution {
public:
    int longestSubsequence(vector<int>& nums) {//TC=O(n), SC=O(1)
        int xorr=0,n=nums.size();
        bool all0=1;
        for(int &e: nums){
            xorr^=e;
            if(e!=0) all0=0;
        }
        if(all0) return 0;
        return (xorr!=0)?n:n-1;
    }
};
