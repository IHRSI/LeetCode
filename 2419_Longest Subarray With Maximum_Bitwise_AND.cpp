/*we can see that the largest bitwise AND can only be achieved when all the elements in the subarray are equal to the maximum number.
So, the task is to find the longest subarray where all the numbers are the maximum value in the array.*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {//O(n) , SC=O(1)
        int ans=0;
        int n=nums.size();
        int mxele=*max_element(nums.begin(),nums.end());
        for(int i=0;i<n;++i){
            int ct=0;
            while(i<n && nums[i]==mxele){
                ++ct;
                ++i;
            }
            ans=max(ans,ct);
        }
        return ans;
    }
};
