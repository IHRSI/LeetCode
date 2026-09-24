class Solution {
public:
    int smallestIndex(vector<int>& nums) {//TC=O(nlogm), SC=O(1)
        int n=nums.size();
        for(int i=0;i<n;++i){
            int sum=0;
            while(nums[i]>0){
                sum+=nums[i]%10;
                nums[i]/=10;
            }
            if(i==sum) return i;
        }
        return -1;
    }
};
