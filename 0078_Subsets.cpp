// Both methods are efficient
// Used backtracking
/*Space Complexity (SC):
Recursion stack space: At most O(n) (the depth of recursion).
Answer space (ans): 2^n subsets, each of size up to n:O(n*n^2)
Auxiliary vector v: Takes O(n) space during recursion.
​*/
class Solution {// TC=SC=O(n*2^n) , This takes more space as it also requires recursion stack space.
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
class Solution {// TC=SC=O(n*2^n) , takes less space
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=1<<nums.size();
        for(int mask=0; mask<n;++mask){
            vector<int> v;
            for(int i=0;i<nums.size();++i){
                if((mask & (1<<i)) !=0) v.push_back(nums[i]);// checking set bit
            }
            ans.push_back(v);
        }
        return ans;
    }
};
