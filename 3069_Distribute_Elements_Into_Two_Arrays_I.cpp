//Simulation
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {//TC=O(n), SC=O(n)
        vector<int> a1,a2;
        int n=nums.size();
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        for(int i=2;i<n;++i){
            if(a1.back()>a2.back()) a1.push_back(nums[i]);
            else a2.push_back(nums[i]);
        }
        for(int e: a2) a1.push_back(e);
        return a1;
    }
};


//Simulation + 2ptr
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {//TC=O(n), SC=O(1) , Apart from the output array itself, we only use a constant number of additional variables.
        int n=nums.size();
        vector<int> ans(n);
        ans[0]=nums[0];
        ans[n-1]=nums[1];
        int idx=0,revidx=n-1;
        for(int i=2;i<n;++i){
            if(ans[idx]>ans[revidx]){
                ans[++idx]=nums[i];
            }
            else ans[--revidx]=nums[i];
        }
        reverse(ans.begin()+revidx,ans.end());
        return ans;
    }
};
