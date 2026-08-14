class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {//TC=O(n), SC=O(n)
        int n=nums.size();
        unordered_map<int,int> um;
        int ans=0,i=0,j=0;
        while(j<n){
            ++um[nums[j]];
            if(um[nums[j]]<=k){
                ans=max(ans,j-i+1);
            }
            else{
                while(um[nums[j]]>k){
                    --um[nums[i]];
                    ++i;
                }
            }
            ++j;
        }
        return ans;
    }
};

//Simplified from above code - removed the if else
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {//TC=O(n), SC=O(n)
        int n=nums.size();
        unordered_map<int,int> um;
        int ans=0,i=0,j=0;
        while(j<n){
            ++um[nums[j]];
            while(um[nums[j]]>k){
                --um[nums[i]];
                ++i;
            }
            ans=max(ans,j-i+1);
            ++j;
        }
        return ans;
    }
};
