class Solution {
public:
    bool isGood(vector<int>& nums) {//TC=O(n), SC=O(n)
        int n=nums.size()-1;
        vector<bool> check(n+1);
        int ctn=0;
        for(int e: nums){
            if(e>n) return 0;
            else if(e<n && check[e]!=false) return 0;
            else if(e==n){
                ++ctn;
                if(ctn>2) return 0;
            }
            check[e]=1;
        }
        return 1;
    }
};

class Solution {
public:
    bool isGood(vector<int>& nums) {//TC=O(nlogn), SC=O(logn)
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        for(int i=0;i<n;++i){
            if(nums[i]!=i+1) return 0;
        }
        return (nums[n]==n)?1:0;
    }
};
