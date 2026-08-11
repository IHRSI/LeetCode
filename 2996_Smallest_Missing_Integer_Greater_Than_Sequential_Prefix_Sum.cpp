class Solution {
public:
    int missingInteger(vector<int>& nums) {//TC=O(3n)~O(n), SC=O(n)
        int presum=nums[0], n=nums.size();
        unordered_set<int> us(nums.begin(),nums.end());
        for(int i=1;i<n;++i){
            if(nums[i]==nums[i-1]+1) presum+=nums[i];
            else break;
        }
        while(us.count(presum)) ++presum;
        return presum;
    }
};

//Used bool arr as constraints were small
class Solution {
public:
    int missingInteger(vector<int>& nums) {//TC=O(n), SC=O(50)~O(1)
        int sequentialSum = nums[0];
        int n = nums.size();
        bool freq[51]={0};
        freq[nums[0]]=1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sequentialSum += nums[i];
                freq[nums[i]] = 1;
            } else {
                while (i < n) {
                    freq[nums[i]] = 1;
                    i++;
                }
            }
        }
        if(sequentialSum>50) return sequentialSum;
        while (sequentialSum <= 50 && freq[sequentialSum] == 1) ++sequentialSum;
        return sequentialSum;
    }
};
