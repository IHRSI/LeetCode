class Solution {
public:
    int specialTriplets(vector<int>& nums) {//TC=O(n), SC=O(2n) or O(6e5)
        int ans=0,m=1e9+7;
        int n=nums.size();
        unordered_map<int,int> rum;//vector<int> rum(3e5);Using vector less space and better runtime
        unordered_map<int,int> lum;//vector<int> lum(3e5);
        for(int i=0;i<n;++i){
            rum[nums[i]]++;
        }
        for(int j=0;j<n;++j){
            rum[nums[j]]--;
            int num=nums[j]<<1;
            ans=(ans+0ll+(lum[num]*1ll*rum[num])%m)%m;
            lum[nums[j]]++;
        }
        return ans;
    }
};

//Ed soln - Has better runtime than above due to:
//sparse
//cache-friendly
//skips most j values
//binary-search on tiny vectors - so almost constant

class Solution {
public:
    int specialTriplets(vector<int>& nums) {//TC=O(nlogn), SC=O(n)
        const int MOD = 1e9 + 7;
        unordered_map<int, vector<int>> pos;
        pos.reserve(nums.size() * 2);
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }
        int ans = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            int target = nums[i] * 2LL;
            if (pos.count(target) == 0) {
                continue;
            }
            const auto& arr = pos[target];
            if (arr.size() <= 1 || arr[0] >= i) {
                continue;
            }
            auto split = upper_bound(arr.begin(), arr.end(), i);
            int l = split - arr.begin();
            int r = arr.size() - l;
            if (nums[i] == 0) {//Edge case
                l--;
            }
            ans = (ans + l * 1LL * r % MOD) % MOD;
        }
        return ans;
    }
};

class Solution {
public:
    int specialTriplets(vector<int>& nums) {//TC=O(n^3), SC=O(1)
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n-2;++i){
            for(int j=i+1;j<n-1;++j){
                for(int k=j+1;k<n;++k){
                    if(nums[j]*2==nums[i] && nums[j]*2==nums[k]) ++ans;
                }
            }
        }
        return ans;
    }
};
