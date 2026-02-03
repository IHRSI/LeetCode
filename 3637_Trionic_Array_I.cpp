//Boundary Checking
class Solution {
public:
    bool isTrionic(vector<int>& nums) {//TC=O(n), SC=O(1)
        int i=1,n=nums.size();
        while(i<n && nums[i]>nums[i-1]) ++i;
        if(i==1 || i>n-2) return 0;
        while(i<n && nums[i]<nums[i-1]) ++i;
        if(i>n-1) return 0;
        while(i<n && nums[i]>nums[i-1]) ++i;
        if(i==n) return 1;
        return 0;
    }
};

//Counting no. of turning points
class Solution {
public:
    bool isTrionic(vector<int>& nums) {//TC=O(n), SC=O(1)
        int n=nums.size();
        if(nums[0]>=nums[1]) return 0;
        int ct=1;
        for(int i=2;i<n;++i){
            if(nums[i]==nums[i-1]) return 0;
            if((nums[i-2]-nums[i-1])*(nums[i-1]-nums[i])<0) ++ct;
            if(ct>3) return 0;
        }
        return ct==3;
    }
};
