class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> um;
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;++i){
            um[nums[i]].push_back(i);
        }
        for(auto &[x,arr]: um){
            if(arr.size()<3) continue;
            for(int i=2;i<arr.size();++i){
                ans=min(ans,(arr[i]-arr[i-2]));
            }
        }
        return ans!=INT_MAX?2*ans:-1;
    }
};
