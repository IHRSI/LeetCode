class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {//TC=O(n*31)=O(nlogm)~O(n), SC=O(1)
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]==2) nums[i]=-1;
            else{
                for(int j=1;j<32;++j){
                    if((nums[i] &(1<<j))==0){
                        nums[i]^=(1<<(j-1));
                        break;
                    }
                }
            }
        }
        return nums;
    }
};
