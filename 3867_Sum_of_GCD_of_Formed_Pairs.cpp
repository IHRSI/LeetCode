class Solution {
public:
    long long gcdSum(vector<int>& nums) {//TC=O(nlogM+nlogn+n/2*logM)~O(n(logn+logM)), SC=O(logn)
        int n=nums.size();
        int mx=nums[0];
        for(int i=1;i<n;++i){
            mx=max(mx,nums[i]);
            nums[i]=__gcd(mx,nums[i]);
        }
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        long long sum=0;
        while(i<j){
            sum+=__gcd(nums[i],nums[j]);
            ++i;
            --j;
        }
        return sum;
    }
};
