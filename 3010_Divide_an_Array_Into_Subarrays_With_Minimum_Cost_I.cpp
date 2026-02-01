//Enumeration
class Solution {
public:
    int minimumCost(vector<int>& nums) {//TC=O(n), SC=O(1)
        int s1=INT_MAX,s2=INT_MAX;
        for(int i=1;i<nums.size();++i){
            if(s1>nums[i]){
                s2=s1;
                s1=nums[i];
            }
            else if(s2>nums[i]) s2=nums[i];
        }
        return nums[0]+s1+s2;
    }
};

//Sorting
class Solution {
public:
    int minimumCost(vector<int>& nums) {//TC=O(nlogn), SC=O(logn)
        sort(nums.begin()+1,nums.end());
        return nums[0]+nums[1]+nums[2];
    }
};
