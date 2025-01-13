//Brute Force Method
class Solution {//TC=O(n^2) SC=O(1)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(target==nums[i]+nums[j]){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

//Optimised
class Solution {// TC=O(n), SC=(n)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int temp = nums[i];
            int rem = target-temp;
            if(map.find(rem)!= map.end()){
                ans.push_back(map[rem]);
                ans.push_back(i);
                return ans;
            }
            map[nums[i]]=i;
        }
        return ans;
    }
};
