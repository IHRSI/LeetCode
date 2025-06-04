//Prefix Sum + Hash Map or //We hash the prefic sum value
//Cumulative Sum + Frequency Counting
class Solution {// TC=O(n) ,  SC=(n) , Tricky logic -total - k is a key point.
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        um[0] = 1;// initially the presem is 0 therefore 0 count is 1
        int presum = 0, ans = 0;
        for (int n : nums) {
            presum += n;
            if (um.find(presum - k) != um.end()) {//O(1)
                ans += um[presum - k];
            }
            um[presum]++;
        }
        return ans;
    }
};

//Only Prefix sum
class Solution { // TC=O(n^2) , SC=O(1)
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]==k) ans+=1;
            for (int j = 0; j < i; j++) {
                if (nums[i] - nums[j] == k) ans++;
            }
        }
        return ans;
    }
};
