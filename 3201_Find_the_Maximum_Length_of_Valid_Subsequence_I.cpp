class Solution {
public:
    int maximumLength(vector<int>& nums) {//TC=O(n) , SC=O(1)
        int even_ct=0,odd_ct=0;
        for(int i:nums){
            if(i&1) ++odd_ct;
            else ++even_ct;
        }
        int prev_parity=nums[0]%2;
        int alter_ct=1;
        for(int i=1;i<nums.size();++i){
            int curr_parity=nums[i]%2;
            if(prev_parity!=curr_parity){
                ++alter_ct;
                prev_parity=curr_parity;
            }
        }
        return max({even_ct,odd_ct,alter_ct});
    }
};
