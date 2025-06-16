//Similar to Q 121 Buy and sell stocks

//Greeedy with one pass optimisation - Efficient
class Solution {//TC=O(n) , SC=O(1)
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        int n=nums.size();
        int min=nums[0];
        for(int i=1;i<n;++i){
            if(nums[i]>min) ans=max(ans,nums[i]-min);
            else min=nums[i];
        }
        return ans;
    }
};

//2pointer - This is also efficient
class Solution {//TC=O(n) , SC=O(1)
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        int n=nums.size();
        int l=0,r=1;
        while(r<n){
            if(nums[r]>nums[l]){
                ans=max(ans,nums[r]-nums[l]);
                ++r;
            }
            else{
                l=r;
                ++r;
            }
        }
        return ans;
    }
};
