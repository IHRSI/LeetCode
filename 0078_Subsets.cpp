// Both methods are efficient
// Used backtracking
class Solution {// TC=SC=O(n*2^n)
public:
    vector<vector<int>> ans;
    void subset(vector<int> &v,int i,vector<int> &nums){
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        subset(v,i+1,nums);
        v.push_back(nums[i]);
        subset(v,i+1,nums);
        v.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        subset(v,0,nums);
        return ans;
    }
};

//Using Bitmasing
