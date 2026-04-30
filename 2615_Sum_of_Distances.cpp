//Prefix Sum
class Solution {
public:
    vector<long long> distance(vector<int>& nums){//TC=O(2n)~O(n), SC=O(n)
        int n=nums.size();
        vector<long long> ans(n);
        unordered_map<int,pair<int,long long>> psum;// element -> (no. of index count,prefix sum of indexes)
        for(int i=0;i<n;++i){//Forward
            if(psum[nums[i]].first>0){
                ans[i]=i*1ll*psum[nums[i]].first-psum[nums[i]].second;
            }
            ++psum[nums[i]].first;
            psum[nums[i]].second+=i;
        }
        psum.clear();
        for(int i=n-1;i>=0;--i){//Backward
            if(psum[nums[i]].first>0){
                ans[i]+=psum[nums[i]].second-i*1ll*psum[nums[i]].first;
            }
            ++psum[nums[i]].first;
            psum[nums[i]].second+=i;
        }
        return ans;
    }
};

//Brute Force - TLE
class Solution {
public:
    vector<long long> distance(vector<int>& nums){//TC=O(n^2), SC=O(1)
        int n=nums.size();
        vector<long long> ans(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i!=j && nums[i]==nums[j]) ans[i]+=0ll+abs(i-j);
            }
        }
        return ans;
    }
};
