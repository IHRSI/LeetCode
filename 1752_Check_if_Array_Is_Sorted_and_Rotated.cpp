class Solution {
public:
    bool check(vector<int>& nums) {//TC=O(n), SC=O(1)
        int n=nums.size();
        int change=0;
        for(int i=0;i<n;++i){
            if(nums[i]>nums[(i+1)%n]) ++change;
        }
        return change<=1;
    }
};
