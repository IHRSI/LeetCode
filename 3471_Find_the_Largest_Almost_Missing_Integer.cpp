class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {//TC=O(n+n+50)~O(n), SC=O(51)~(1)
        int n=nums.size();
        if(k==n) return *max_element(nums.begin(),nums.end());
        int arr[51]={0};
        for(int e: nums) ++arr[e];
        if(k==1){
            for(int i=50;i>=0;--i) if(arr[i]==1) return i;
          return -1;
        }
        if(arr[nums[0]]==1 && arr[nums[n-1]]==1) return max(nums[0],nums[n-1]);
        else if(arr[nums[0]]==1) return nums[0];
        else if(arr[nums[n-1]]==1) return nums[n-1];
        return -1;
    }
};
