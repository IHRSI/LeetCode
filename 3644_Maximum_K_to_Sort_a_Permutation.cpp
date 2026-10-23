class Solution {
public:
    int sortPermutation(vector<int>& nums) {//TC=O(n), SC=O(1)
        int k=-1,n=nums.size();
        for(int i=0;i<n;++i) if(i!=nums[i]) k=k&nums[i];
        return (k!=-1)?k:0;
    }
};
