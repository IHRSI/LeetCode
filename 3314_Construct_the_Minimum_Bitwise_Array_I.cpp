class Solution {//Brute Force
public:
    vector<int> minBitwiseArray(vector<int>& nums) {//TC=O(n*max(nums[i])), SC=O(1)
        for(int i=0;i<nums.size();++i){
            int temp=nums[i];
            for(int j=1;j<temp;++j){
                if((j|(j+1))==nums[i]){
                    nums[i]=j;
                    break;
                }
            }
            if(nums[i]==temp) nums[i]=-1;
        }
        return nums;
    }
};
