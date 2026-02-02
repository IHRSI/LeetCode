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

//Approach 2- Using LIS Pattern (Recursion)
//T.C : Without Memoization O(2^n) - Gives TLE
//S.C : O(n)
class Solution {
public:
    int LIS(vector<int>& nums, int i, int prev, int mod) {
        if(i >= nums.size()) {
            return 0;
        }
        int take = 0;
        int skip = 0;
        //take
        if(prev == -1 || (nums[prev] + nums[i])%2 == mod) {
            take = 1 + LIS(nums, i+1, i, mod);
        }
        //skip
        skip = LIS(nums, i+1, prev, mod);
        return max(take, skip);
    }
    int maximumLength(vector<int>& nums) {
        int maxSubLength = 0;
        maxSubLength = max(maxSubLength, LIS(nums, 0, -1, 0)); //%2 == 0 k lie
        maxSubLength = max(maxSubLength, LIS(nums, 0, -1, 1)); //%2 == 1 k lie
        return maxSubLength;
    }
};

//T.C : With memoization - O(n^2) - Memoization will give MLE due to high constraints
//S.C : O(n^2) but MLE
