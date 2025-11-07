class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {//TC=O(n*k*logk), SC=O(k)
        int n=nums.size();
        vector<int> ans(n-k+1);
        for(int i=0;i<n-k+1;++i){
            int xsum=0;
            unordered_map<int,int> um;
            for(int j=i;j<k+i;++j){
                ++um[nums[j]];
            }
            vector<pair<int,int>> vp;
            for(auto &ele: um){
                vp.emplace_back(ele.second,ele.first);
            }
            sort(vp.begin(),vp.end(),greater<pair<int,int>>());
            for(int j=0; j<x && j<vp.size(); ++j){
                xsum+=vp[j].first*vp[j].second;
            }
            ans[i]=xsum;
        }
        return ans;
    }
};
