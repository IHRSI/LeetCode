class Solution {
public:
    void nextPermutation(vector<int>& nums) {//TC=O(3n)~O(n), SC=O(1)
        int n=nums.size();
        bool largest=true;
        for(int i=n-2;i>=0;--i){
            if(nums[i]<nums[i+1]){
                largest=false;
                int nxt_greater_idx=i+1;
                for(int j=n-1;j>i;--j){
                    if(nums[j]>nums[i]){
                        nxt_greater_idx=j;
                        break;
                    }
                }
                swap(nums[i],nums[nxt_greater_idx]);
                reverse(nums.begin()+i+1,nums.end());
                break;
            }
        }
        if(largest) reverse(nums.begin(),nums.end());
        return ;
    }
};
