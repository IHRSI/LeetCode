class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {//TC=O(n) , SC=O(1)
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;++i){
            int temp=0;
            while(i<n && nums[i]==0){
                ++i;
                ++temp;
            }
            ans+=temp*1ll*(temp+1)/2;
        }
        return ans;
    }
};

/* Alternative logic inside for loop
if(nums[i]==0){
    ++temp;
    ans+=temp;
}
else temp=0;
*/
/*
Approach:
We traverse the array once while maintaining a counter (streak) for consecutive zeros.

If the current element is 0, we extend the streak by +1.
Every new zero extends all previous zero-subarrays and also forms a new single-element subarray.
So we add streak to our answer.
If the current element is non-zero, we reset streak = 0 because a zero-filled subarray cannot continue past it.
By accumulating in this way, we efficiently count all zero-filled subarrays in a single pass.
*/
*/
