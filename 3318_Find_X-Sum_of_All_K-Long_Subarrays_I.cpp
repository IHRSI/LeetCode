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
            vector<pair<int,int>> vp;//could have used pq(max heap) here
            for(auto &ele: um){
                vp.emplace_back(ele.second,ele.first);
            }
            sort(vp.begin(),vp.end(),greater<pair<int,int>>());
            for(int j=0; j<x && j<vp.size(); ++j){
                xsum+=vp[j].first*vp[j].second;
            }
            /*
            priority_queue<pair<int,int>> pq;
            for(auto ele: um){
                pq.push({ele.second,ele.first});
            }
            for(int k=0;k<x && k<um.size();++k){
                xsum+=pq.top().first*pq.top().second;
                pq.pop();
            }
            */
            ans[i]=xsum;
        }
        return ans;
    }
};
