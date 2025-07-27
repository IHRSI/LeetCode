//Removed Duplicates
class Solution {
public:
    int countHillValley(vector<int>& nums) {//TC=O(n) , SC=O(n)
        int ans=0;
        int n=nums.size();
        vector<int> uniq;
        uniq.push_back(nums[0]);
        for(int i=1;i<n;++i){
            if(nums[i]==nums[i-1]) continue;
            uniq.push_back(nums[i]);
        }
        for(int i=1;i<uniq.size()-1;++i){
            if(uniq[i]>uniq[i-1] && uniq[i]>uniq[i+1]) ++ans;
            if(uniq[i]<uniq[i-1] && uniq[i]<uniq[i+1]) ++ans;
        }
        return ans;
    }
};

//Without removing duplicates
class Solution {
public:
    int countHillValley(vector<int>& nums) {//TC=O(n^2), SC=O(1)
        int ans=0;
        int n=nums.size();
        for(int i=1;i<n-1;++i){
            if(nums[i]==nums[i-1]) continue;//To avoid dupicate hills and valleys
            else{
                int j=i-1,k=i+1;
                while(k<n){
                    if(nums[i]==nums[k]) ++k;
                    else break;
                }
                while(j>=0){
                    if(nums[i]==nums[j]) --j;
                    else break;
                }
                if(k<n && j>=0){
                    if(nums[i]>nums[j] && nums[i]>nums[k]) ++ans;
                    if(nums[i]<nums[j] && nums[i]<nums[k]) ++ans;
                }
            }
        }
        return ans;
    }
};
