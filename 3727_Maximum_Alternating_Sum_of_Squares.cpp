class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {//TC=O(n+nlogn+n)~O(nlogn), SC=O(logn)
        long long ans=0;
        for(int &e:nums) if(e<0) e*=-1;
        sort(nums.begin(),nums.end());
        int n=nums.size(),i=0;
        for(i;i<n/2;++i) ans-=nums[i]*1ll*nums[i];
        for(i;i<n;++i) ans+=nums[i]*1ll*nums[i];
        return ans;
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {//TC=O(n+nlogn+n)~O(nlogn), SC=O(logn)
        long long ans=0;
        for(int &e:nums) e*=e;
        sort(nums.begin(),nums.end());
        int n=nums.size(),i=0;
        return accumulate(nums.begin()+nums.size()/2,nums.end(),0ll)
        -accumulate(nums.begin(),nums.begin()+nums.size()/2,0ll);
    }
};
