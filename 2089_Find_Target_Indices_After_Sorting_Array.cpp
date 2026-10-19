class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {//TC=O(n), SC=O(1)
        vector<int> ans;
        int ct_tar=0,ct_less=0,n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]<target) ++ct_less;
            else if(nums[i]==target) ++ct_tar;
        }
        while(ct_tar--){
            ans.push_back(ct_less);
            ++ct_less;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {//TC+O(nlogn), SC=O(logn)
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i) if(nums[i]==target) ans.push_back(i);
        return ans;
    }
};
