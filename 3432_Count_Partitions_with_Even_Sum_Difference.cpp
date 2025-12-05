class Solution {//Maths odd even logic analysis
public:
    int countPartitions(vector<int>& nums) {//TC=O(n), SC=O(1)
        int sum=accumulate(nums.begin(),nums.end(),0);
        return (sum%2==0)?nums.size()-1:0;
    }
};

class Solution {
public:
    int countPartitions(vector<int>& nums) {//TC=O(n), SC=O(1)
        int sum=accumulate(nums.begin(),nums.end(),0);
        int psum,ans=0;
        for(int i=0;i<nums.size()-1;++i){
            psum+=nums[i];
            int diff=sum-psum;
            if((psum-diff)%2==0) ++ans;
        }
        return ans;
    }
};
