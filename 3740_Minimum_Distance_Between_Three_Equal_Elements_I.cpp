//Hashing UM(int,vec)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {//TC=O(2n)~O(n), SC=O(1)
        unordered_map<int,vector<int>> um;
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;++i){
            um[nums[i]].push_back(i);
        }
        for(auto &[x,arr]: um){
            if(arr.size()<3) continue;
            for(int i=2;i<arr.size();++i){
                ans=min(ans,2*(arr[i]-arr[i-2]));
            }
        }
        return ans!=INT_MAX?ans:-1;
    }
};

//Brute force
class Solution {
public:
    int minimumDistance(vector<int>& nums) {//TC=O(n^3), SC=O(1)
        int n = nums.size();
        int ans = n + 1;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[i] != nums[j]) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    if (nums[j] == nums[k]) {
                        ans = min(ans, k - i);
                        break;
                    }
                }
            }
        }
        return ans == n + 1 ? -1 : ans * 2;
    }
};
