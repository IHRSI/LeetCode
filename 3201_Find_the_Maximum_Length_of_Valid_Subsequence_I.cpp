//Q mentioned DP but used greedy parity enumeration
/*
All you need to do is:
While traversing the array, count the number of even numbers and the number of instances where the current number
is the opposite parity of the one before it (i.e. if nums[i - 1] is even and nums[i] is odd, or vice versa)
Return whichever value is largest: the number of even numbers, the number of odd numbers (calculated by subtracting
the number of even numbers from the length of the nums), or the number of opposite parities.
*/
//Give this a thought then get the intution. As mod 2 gives only values 0 or 1.
//(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
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
