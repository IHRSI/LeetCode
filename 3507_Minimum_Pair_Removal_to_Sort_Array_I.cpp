class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {//TC=O(n(n+n))~O(n^2), SC=O(1)
        int ans=0;
        while(!is_sorted(nums.begin(),nums.end())){
            ++ans;
            int n=nums.size();
            int min_sum_idx=0;
            int min_sum=INT_MAX;
            for(int i=0;i<n-1;++i){
                if(nums[i]+nums[i+1]<min_sum){
                    min_sum_idx=i;
                    min_sum=nums[i]+nums[i+1];
                }
            }
            nums[min_sum_idx]=min_sum;
            nums.erase(nums.begin()+min_sum_idx+1);
        }
        return ans;
    }
};
