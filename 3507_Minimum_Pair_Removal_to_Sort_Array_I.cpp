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

//Making the erase as O(1) using SC by using linked list logic/implementation in array
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {//TC=O(n^2), SC=O(n)
        int n = nums.size();
        vector<int> next(n, -1);
        // build linked list
        for (int i = 0; i < n - 1; ++i)
            next[i] = i + 1;
        int ans = 0;
        while (true) {
            bool sorted = true;
            int min_sum = INT_MAX;
            int min_idx = -1;
            // traverse list
            for (int i = 0; next[i] != -1; i = next[i]) {
                int j = next[i];
                if (nums[i] > nums[j])
                    sorted = false;
                int s = nums[i] + nums[j];
                if (s < min_sum) {
                    min_sum = s;
                    min_idx = i;
                }
            }
            if (sorted) break;
            // merge min_idx and next[min_idx]
            int j = next[min_idx];
            nums[min_idx] = min_sum;
            next[min_idx] = next[j];   // O(1) deletion
            ++ans;
        }
        return ans;
    }
};
