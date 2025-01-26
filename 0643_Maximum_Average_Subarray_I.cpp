// Efficient used precomputing constant sliding window
class Solution {//TC- O(n), SC=O(1)
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxavg;
        int n=nums.size();
        int l=0,r=k;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        maxavg=sum;
        while(r<n){
            sum=sum+nums[r]-nums[l];
            maxavg=max(maxavg,sum);
            ++l;
            ++r;
        }
        return maxavg*1.0/k;
    }
};
